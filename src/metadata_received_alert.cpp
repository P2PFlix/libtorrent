#include "main.hpp"
Libtorrent::MetadataReceivedAlert::MetadataReceivedAlert(const Napi::CallbackInfo &info) : Napi::ObjectWrap<MetadataReceivedAlert>(info)
{
    this->metadata_received_alert = nullptr;
}
Napi::Function Libtorrent::MetadataReceivedAlert::Init(Napi::Env env)
{
    return DefineClass(env, "MetadataReceivedAlert", {
                                                         InstanceAccessor<&MetadataReceivedAlert::GetMetadataReceivedAlert, &MetadataReceivedAlert::SetMetadataReceivedAlert>("metadataReceivedAlert"),
                                                         InstanceAccessor<&MetadataReceivedAlert::GetHandle, &MetadataReceivedAlert::SetHandle>("handle"),
                                                     });
}
Napi::Value Libtorrent::MetadataReceivedAlert::GetMetadataReceivedAlert(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::metadata_received_alert>::New(env, this->metadata_received_alert);
}
void Libtorrent::MetadataReceivedAlert::SetMetadataReceivedAlert(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::metadata_received_alert *metadata_received_alert = value.As<Napi::External<libtorrent::metadata_received_alert>>().Data();
    this->metadata_received_alert = metadata_received_alert;
}
Napi::Value Libtorrent::MetadataReceivedAlert::GetHandle(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    libtorrent::torrent_handle torrent_handle = this->metadata_received_alert->handle;
    Napi::Object torrent_handle_arg = TorrentHandle::Init(env).New({});
    torrent_handle_arg.Set("torrentHandle", Napi::External<libtorrent::torrent_handle>::New(env, new libtorrent::torrent_handle(torrent_handle)));
    return torrent_handle_arg;
}
void Libtorrent::MetadataReceivedAlert::SetHandle(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    Napi::Object torrent_handle_arg = value.As<Napi::Object>();
    libtorrent::torrent_handle *torrent_handle = torrent_handle_arg.Get("torrentHandle").As<Napi::External<libtorrent::torrent_handle>>().Data();
    this->metadata_received_alert->handle = *torrent_handle;
}
