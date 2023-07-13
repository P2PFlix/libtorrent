#include "main.hpp"
Libtorrent::DhtSampleInfohashesAlert::DhtSampleInfohashesAlert(const Napi::CallbackInfo &info) : Napi::ObjectWrap<DhtSampleInfohashesAlert>(info)
{
    this->dht_sample_infohashes_alert = nullptr;
}
Napi::Function Libtorrent::DhtSampleInfohashesAlert::Init(Napi::Env env)
{
    return DefineClass(env, "DhtSampleInfohashesAlert", {
                                                            InstanceAccessor<&DhtSampleInfohashesAlert::GetDhtSampleInfohashesAlert, &DhtSampleInfohashesAlert::SetDhtSampleInfohashesAlert>("dhtSampleInfohashesAlert"),
                                                            InstanceMethod<&DhtSampleInfohashesAlert::Samples>("samples"),
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
Napi::Value Libtorrent::DhtSampleInfohashesAlert::Samples(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::Array samples_arg = Napi::Array::New(env);
    std::vector<libtorrent::sha1_hash> samples = this->dht_sample_infohashes_alert->samples();
    for (libtorrent::sha1_hash sample : samples)
    {
        Napi::Object sample_arg = Sha1Hash::Init(env).New({});
        sample_arg.Set("sha1Hash", Napi::External<libtorrent::sha1_hash>::New(env, new libtorrent::sha1_hash(sample)));
        samples_arg.Set(samples_arg.Length(), sample_arg);
    }
    return samples_arg;
}
