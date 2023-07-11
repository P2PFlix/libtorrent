#include "main.hpp"
Libtorrent::DhtSampleInfohashesAlert::DhtSampleInfohashesAlert(const Napi::CallbackInfo &info) : Napi::ObjectWrap<DhtSampleInfohashesAlert>(info)
{
    this->dht_sample_infohashes_alert = nullptr;
}
Napi::Function Libtorrent::DhtSampleInfohashesAlert::Init(Napi::Env env)
{
    return DefineClass(env, "DhtSampleInfohashesAlert", {
                                            InstanceAccessor<&DhtSampleInfohashesAlert::GetDhtSampleInfohashesAlert, &DhtSampleInfohashesAlert::SetDhtSampleInfohashesAlert>("dhtSampleInfohashesAlert"),
                                        });
}
Napi::Value Libtorrent::DhtSampleInfohashesAlert::GetDhtSampleInfohashesAlert(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::dht_sample_infohashes_alert>::New(env, this->dht_sample_infohashes_alert);
}
void Libtorrent::DhtSampleInfohashesAlert::SetDhtSampleInfohashesAlert(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::dht_sample_infohashes_alert *dht_sample_infohashes_alert = value.As<Napi::External<libtorrent::dht_sample_infohashes_alert>>().Data();
    this->dht_sample_infohashes_alert = dht_sample_infohashes_alert;
}
