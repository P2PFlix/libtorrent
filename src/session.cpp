#include "session.hpp"
Libtorrent::Session::Session(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Session>(info)
{
    if (info.Length() < 1)
    {
        this->session = new libtorrent::session();
    }
    else
    {
        Napi::Object session_params_arg = info[0].As<Napi::Object>();
        libtorrent::session_params *session_params = session_params_arg.Get("sessionParams").As<Napi::External<libtorrent::session_params>>().Data();
        this->session = new libtorrent::session(*session_params);
    }
}
Napi::Function Libtorrent::Session::Init(Napi::Env env)
{
    return DefineClass(env, "Session", {
                                           InstanceMethod<&Session::IsValid>("isValid"),
                                           InstanceMethod<&Session::DhtSampleInfohashes>("dhtSampleInfohashes"),
                                       });
}
Napi::Value Libtorrent::Session::IsValid(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Boolean::New(env, this->session->is_valid());
}
Napi::Value Libtorrent::Session::DhtSampleInfohashes(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::Object endpoint_arg = info[0].As<Napi::Object>();
    Napi::Object sha1_hash_arg = info[1].As<Napi::Object>();
    libtorrent::udp::endpoint *endpoint = endpoint_arg.Get("endpoint").As<Napi::External<libtorrent::udp::endpoint>>().Data();
    libtorrent::sha1_hash *sha1_hash = sha1_hash_arg.Get("sha1Hash").As<Napi::External<libtorrent::sha1_hash>>().Data();
    this->session->dht_sample_infohashes(*endpoint, *sha1_hash);
    return env.Null();
}
