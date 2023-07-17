#include "main.hpp"
Libtorrent::AddTorrentParams::AddTorrentParams(const Napi::CallbackInfo &info) : Napi::ObjectWrap<AddTorrentParams>(info)
{
    if (info.Length() < 1)
    {
        this->add_torrent_params = new libtorrent::add_torrent_params();
    }
    else
    {
        Napi::Object add_torrent_params_arg = info[0].As<Napi::Object>();
        libtorrent::add_torrent_params *add_torrent_params = add_torrent_params_arg.Get("addTorrentParams").As<Napi::External<libtorrent::add_torrent_params>>().Data();
        this->add_torrent_params = new libtorrent::add_torrent_params(*add_torrent_params);
    }
}
Napi::Function Libtorrent::AddTorrentParams::Init(Napi::Env env)
{
    return DefineClass(env, "AddTorrentParams", {
                                                    InstanceAccessor<&AddTorrentParams::GetAddTorrentParams, &AddTorrentParams::SetAddTorrentParams>("addTorrentParams"),
                                                    InstanceAccessor<&AddTorrentParams::GetFlags, &AddTorrentParams::SetFlags>("flags"),
                                                    InstanceAccessor<&AddTorrentParams::GetInfoHashes, &AddTorrentParams::SetInfoHashes>("infoHashes"),
                                                });
}
Napi::Value Libtorrent::AddTorrentParams::GetAddTorrentParams(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::add_torrent_params>::New(env, this->add_torrent_params);
}
void Libtorrent::AddTorrentParams::SetAddTorrentParams(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::add_torrent_params *add_torrent_params = value.As<Napi::External<libtorrent::add_torrent_params>>().Data();
    this->add_torrent_params = add_torrent_params;
}
Napi::Value Libtorrent::AddTorrentParams::GetFlags(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::Object torrent_flags_t_arg = TorrentFlagsT::Init(env).New({});
    torrent_flags_t_arg.Set("torrentFlagsT", Napi::External<libtorrent::torrent_flags_t>::New(env, new libtorrent::torrent_flags_t(this->add_torrent_params->flags)));
    return torrent_flags_t_arg;
}
void Libtorrent::AddTorrentParams::SetFlags(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::torrent_flags_t *torrent_flags_t = value.As<Napi::Object>().Get("torrentFlagsT").As<Napi::External<libtorrent::torrent_flags_t>>().Data();
    this->add_torrent_params->flags = *torrent_flags_t;
}
Napi::Value Libtorrent::AddTorrentParams::GetInfoHashes(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::Object info_hash_t_arg = InfoHashT::Init(env).New({});
    info_hash_t_arg.Set("infoHashT", Napi::External<libtorrent::info_hash_t>::New(env, new libtorrent::info_hash_t(this->add_torrent_params->info_hashes)));
    return info_hash_t_arg;
}
void Libtorrent::AddTorrentParams::SetInfoHashes(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::info_hash_t *info_hash_t = value.As<Napi::Object>().Get("infoHashT").As<Napi::External<libtorrent::info_hash_t>>().Data();
    this->add_torrent_params->info_hashes = *info_hash_t;
}
