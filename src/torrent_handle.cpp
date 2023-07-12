#include "main.hpp"
Libtorrent::TorrentHandle::TorrentHandle(const Napi::CallbackInfo &info) : Napi::ObjectWrap<TorrentHandle>(info)
{
    if (info.Length() < 1)
    {
        this->torrent_handle = new libtorrent::torrent_handle();
    }
    else
    {
        Napi::Object torrent_handle_arg = info[0].As<Napi::Object>();
        libtorrent::torrent_handle *torrent_handle = torrent_handle_arg.Get("torrentHandle").As<Napi::External<libtorrent::torrent_handle>>().Data();
        this->torrent_handle = new libtorrent::torrent_handle(*torrent_handle);
    }
}
Napi::Function Libtorrent::TorrentHandle::Init(Napi::Env env)
{
    return DefineClass(env, "TorrentHandle", {
                                            InstanceAccessor<&TorrentHandle::GetTorrentHandle, &TorrentHandle::SetTorrentHandle>("torrentHandle"),
                                        });
}
Napi::Value Libtorrent::TorrentHandle::GetTorrentHandle(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::torrent_handle>::New(env, this->torrent_handle);
}
void Libtorrent::TorrentHandle::SetTorrentHandle(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::torrent_handle *torrent_handle = value.As<Napi::External<libtorrent::torrent_handle>>().Data();
    this->torrent_handle = torrent_handle;
}
