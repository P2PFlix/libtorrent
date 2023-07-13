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
