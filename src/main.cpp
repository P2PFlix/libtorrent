#include <iostream>
#include "main.hpp"

Napi::String LibtorrentNode::getLibTorrentVersion(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  return Napi::String::New(env, lt::version());
}

Napi::Object LibtorrentNode::Init(Napi::Env env, Napi::Object &exports)
{
  exports.Set("getLibTorrentVersion", Napi::Function::New(env, LibtorrentNode::getLibTorrentVersion));
  return exports;
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
  LibtorrentNode::Init(env, exports);
  LibtorrentNode::Client::Init(env, exports);
  LibtorrentNode::Torrent::Init(env, exports);
  return exports;
}

Napi::String LibtorrentNode::Version(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  return Napi::String::New(env, lt::version());
}

lt::torrent_handle LibtorrentNode::findTorrent(lt::session *session, std::uint32_t to_find_id)
{
  std::vector<lt::torrent_handle> torrents = session->get_torrents();

  for (auto const &torrent : torrents)
  {
    std::uint32_t id = torrent.id();

    if (id == to_find_id)
      return torrent;
  }

  lt::torrent_handle none;

  return none;
}

Napi::Object LibtorrentNode::Torrent::NewInstance(Napi::Env env, lt::torrent_handle torrent)
{
  Napi::EscapableHandleScope scope(env);
  if (Torrent::constructor == nullptr)
  {
    Napi::Function func = DefineClass(env,
                                      "Torrent",
                                      {InstanceMethod("info", &Torrent::Info),
                                       InstanceMethod("setLimit", &Torrent::SetLimit),
                                       InstanceMethod("pause", &Torrent::Pause),
                                       InstanceMethod("resume", &Torrent::Resume)});

    Torrent::constructor = Napi::Persistent(func);

    Torrent::constructor.SuppressDestruct();
  }
  _torrent = torrent;
  Napi::Object obj = Torrent::constructor.New({});

  return scope.Escape(napi_value(obj)).ToObject();
}

LibtorrentNode::Torrent::Torrent(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Torrent>(info)
{
  Napi::Env env = info.Env();

  Napi::HandleScope scope(env);

  this->torrent = _torrent;
}

Napi::Value LibtorrentNode::Torrent::Pause(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  try
  {
    this->torrent.pause();
  }
  catch (const std::exception &e)
  {
    Napi::TypeError::New(env, LibtorrentNode::buildErrorMessage({LibtorrentNode::ERRORS[3], e.what()})).ThrowAsJavaScriptException();
  }

  return Napi::Boolean::New(info.Env(), true);
}

Napi::Value LibtorrentNode::Torrent::Resume(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  try
  {
    this->torrent.resume();
  }
  catch (const std::exception &e)
  {
    Napi::TypeError::New(env, LibtorrentNode::buildErrorMessage({LibtorrentNode::ERRORS[4], e.what()})).ThrowAsJavaScriptException();
  }

  return Napi::Boolean::New(info.Env(), true);
}

Napi::Value LibtorrentNode::Torrent::SetLimit(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  size_t argc = info.Length();

  if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsString())
  {
    Napi::TypeError::New(env, LibtorrentNode::buildErrorMessage({LibtorrentNode::INCORRECT_AGUMENTS_SUPPLIED, LibtorrentNode::ERRORS[2]})).ThrowAsJavaScriptException();
  }

  int64_t limit = info[0].As<Napi::Number>().Int64Value();
  std::string type = info[1].As<Napi::String>().Utf8Value();
  bool is_upload = type == "upload";

  try
  {
    if (is_upload)
      this->torrent.set_upload_limit(limit);
    else
      this->torrent.set_download_limit(limit);
  }
  catch (const std::exception &e)
  {
    Napi::TypeError::New(env, LibtorrentNode::buildErrorMessage({LibtorrentNode::ERRORS[2], e.what()})).ThrowAsJavaScriptException();
  }

  return Napi::Boolean::New(env, true);
}

Napi::Value LibtorrentNode::Torrent::GetFiles(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::Array result = Napi::Array::New(env);
  try
  {
    std::vector<lt::open_file_state> files = this->torrent.file_status();
    lt::torrent_status status = this->torrent.status();
    auto torrent_info = status.torrent_file.lock();

    if (!torrent_info->is_valid())
      return result;

    unsigned int num_files = torrent_info->num_files();

    for (lt::file_index_t i(0); static_cast<int>(i) != num_files; ++i)
    {
      Napi::Object entry = Napi::Object::New(env);
      lt::file_storage storage = torrent_info->files();

      entry.Set("size", Napi::Number::New(env, storage.file_size(i)));
      entry.Set("filename", Napi::String::New(env, std::string(storage.file_name(i)).c_str()));
      entry.Set("path", Napi::String::New(env, storage.file_path(i).c_str()));
      result.Set(static_cast<int>(i), entry);
    }
  }
  catch (const std::exception &e)
  {
    Napi::TypeError::New(env, LibtorrentNode::buildErrorMessage({LibtorrentNode::ERRORS[5], e.what()})).ThrowAsJavaScriptException();
  }

  return result;
}

Napi::Value LibtorrentNode::Torrent::Info(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::Object result = Napi::Object::New(env);
  lt::torrent_status status = this->torrent.status();

  static char const *state_str[] = {"Checking (q)",
                                    "Checking",
                                    "Metadata",
                                    "Downloading",
                                    "Finished",
                                    "Seeding",
                                    "Allocating",
                                    "Checking (r)"};

  result.Set("id", this->torrent.id());
  result.Set("downloadLimit", this->torrent.download_limit());
  result.Set("uploadLimit", this->torrent.upload_limit());
  result.Set("name", status.name.c_str());
  result.Set("progress", status.progress_ppm / 1000000.0);
  result.Set("done", status.is_finished);
  result.Set("totalSize", status.total);
  result.Set("magnetURI", lt::make_magnet_uri(this->torrent));
  result.Set("downloaded", status.total_done);
  result.Set("state", state_str[status.state]);
  result.Set("uploadRate", status.upload_rate);
  result.Set("downloadRate", status.download_rate);
  result.Set("path", status.save_path);
  result.Set("numPeers", status.num_peers);
  result.Set("isAutoManaged", static_cast<bool>(status.flags & lt::torrent_flags::auto_managed));
  result.Set("isPaused", static_cast<bool>(status.flags & lt::torrent_flags::paused));
  result.Set("savePath", status.save_path);

  result.Set(
      "timeRemaining",
      status.download_rate != 0 ? ((status.total - status.total_done) / status.download_rate) * 1000.0 : INT_MAX);

  result.Set("files", this->GetFiles(info));

  return result;
}

Napi::Object LibtorrentNode::Torrent::Init(Napi::Env env, Napi::Object exports)
{
  Napi::HandleScope scope(env);
  Napi::Function func = DefineClass(env, "Torrent", {InstanceMethod("pause", &Torrent::Pause), InstanceMethod("resume", &Torrent::Resume), InstanceMethod("setLimit", &Torrent::SetLimit), InstanceMethod("getFiles", &Torrent::GetFiles), InstanceMethod("info", &Torrent::Info)});

  Torrent::constructor = Napi::Persistent(func);
  Torrent::constructor.SuppressDestruct();

  exports.Set(Napi::String::New(env, "Torrent"), func);

  return exports;
}

Napi::Object LibtorrentNode::Client::Init(Napi::Env env, Napi::Object exports)
{
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env,
                                    "Client",
                                    {InstanceMethod("addTorrent", &Client::AddTorrent),
                                     InstanceMethod("getTorrents", &Client::GetTorrents),
                                     InstanceMethod("getTorrent", &Client::GetTorrent),
                                     InstanceMethod("removeTorrent", &Client::RemoveTorrent),
                                     InstanceMethod("getClientInfo", &Client::GetClientInfo),
                                     InstanceMethod("hasTorrents", &Client::HasTorrents),
                                     InstanceMethod("isDestroyed", &Client::IsDestroyed)});

  Client::constructor = Napi::Persistent(func);

  Client::constructor.SuppressDestruct();
  exports.Set(Napi::String::New(env, "Client"), func);

  return exports;
}

LibtorrentNode::Client::Client(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Client>(info)
{
  Napi::Env env = info.Env();

  Napi::HandleScope scope(env);
}

Napi::Value LibtorrentNode::Client::AddTorrent(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  size_t argc = info.Length();

  if (info.Length() < 2 || !info[0].IsString() || !info[1].IsString())
  {
    Napi::TypeError::New(env, LibtorrentNode::buildErrorMessage({LibtorrentNode::INCORRECT_AGUMENTS_SUPPLIED, LibtorrentNode::ERRORS[0]})).ThrowAsJavaScriptException();
  }

  std::string save_path = info[0].As<Napi::String>().Utf8Value();
  std::string torrent = info[1].As<Napi::String>().Utf8Value();

  lt::add_torrent_params params;
  lt::error_code ec;

  params.save_path = save_path;

  if (torrent.substr(0, 8) == "magnet:?")
    lt::parse_magnet_uri(torrent, params, ec);
  else
    params.ti = std::make_shared<lt::torrent_info>(torrent);

  lt::torrent_handle added_torrent = this->session.add_torrent(params);

  return Napi::Number::New(env, added_torrent.id());
}

Napi::Value LibtorrentNode::Client::RemoveTorrent(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  size_t argc = info.Length();

  if (info.Length() != 1 || !info[0].IsString())
  {
    Napi::TypeError::New(env, LibtorrentNode::buildErrorMessage({LibtorrentNode::INCORRECT_AGUMENTS_SUPPLIED, LibtorrentNode::ERRORS[6]})).ThrowAsJavaScriptException();
  }

  std::uint32_t to_find_id = info[0].As<Napi::Number>().Int32Value();
  lt::torrent_handle torrent = findTorrent(&this->session, to_find_id);

  if (torrent.is_valid())
  {
    this->session.remove_torrent(torrent);

    return Napi::Boolean::New(env, true);
  }

  return env.Null();
}

Napi::Value LibtorrentNode::Client::GetTorrents(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::Array result = Napi::Array::New(env);
  unsigned int index = 0;
  std::vector<lt::torrent_handle> torrents = this->session.get_torrents();

  for (auto const &torrent_handle : torrents)
  {
    Napi::Object obj = Torrent::NewInstance(env, torrent_handle);

    result.Set(index, obj);

    ++index;
  }

  return result;
}

Napi::Value LibtorrentNode::Client::GetTorrent(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  size_t argc = info.Length();

  if (info.Length() != 1 && !info[0].IsString())
  {
    Napi::TypeError::New(env, LibtorrentNode::buildErrorMessage({LibtorrentNode::INCORRECT_AGUMENTS_SUPPLIED, LibtorrentNode::ERRORS[1]})).ThrowAsJavaScriptException();
  }
  std::uint32_t to_find_id = info[0].As<Napi::Number>().Int32Value();
  lt::torrent_handle torrent = findTorrent(&this->session, to_find_id);

  return Torrent::NewInstance(env, torrent);
}

Napi::Value LibtorrentNode::Client::GetClientInfo(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::Object result = Napi::Object::New(env);
  std::vector<lt::torrent_handle> torrents = this->session.get_torrents();
  double download_rate = 0.0;
  double upload_rate = 0.0;
  float progress = 0;
  int peers = 0;
  size_t nb_torrents = torrents.size();

  for (auto const &torrent : torrents)
  {
    lt::torrent_status status = torrent.status();
    download_rate += status.download_rate;
    upload_rate += status.upload_rate;
    progress += status.progress;
    peers += status.num_peers;
  }

  result.Set("downloadRate", download_rate);
  result.Set("uploadRate", upload_rate);
  result.Set("ratio", upload_rate / download_rate);
  result.Set("peers", peers);
  result.Set("progress", progress / static_cast<float>(nb_torrents));
  result.Set("nbTorrents", nb_torrents);

  return result;
}

Napi::Value LibtorrentNode::Client::HasTorrents(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  return Napi::Boolean::New(env, this->session.get_torrents().size() != 0);
}

Napi::Value LibtorrentNode::Client::IsDestroyed(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  return Napi::Boolean::New(env, !this->session.is_valid());
}

NODE_API_MODULE(LIBTORRENT_NODE, InitAll)
