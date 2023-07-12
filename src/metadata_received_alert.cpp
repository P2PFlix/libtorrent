#include "main.hpp"
Libtorrent::MetadataReceivedAlert::MetadataReceivedAlert(const Napi::CallbackInfo &info) : Napi::ObjectWrap<MetadataReceivedAlert>(info)
{
    this->metadata_received_alert = nullptr;
}
Napi::Function Libtorrent::MetadataReceivedAlert::Init(Napi::Env env)
{
    return DefineClass(env, "MetadataReceivedAlert", {
                                            InstanceAccessor<&MetadataReceivedAlert::GetMetadataReceivedAlert, &MetadataReceivedAlert::SetMetadataReceivedAlert>("metadataReceivedAlert"),
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
