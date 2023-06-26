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
        if (session_params_arg.Has("settingsPack"))
        {
            libtorrent::settings_pack *settings_pack = session_params_arg.Get("settingsPack").As<Napi::External<libtorrent::settings_pack>>().Data();
            this->session = new libtorrent::session(*settings_pack);
        }
        else
        {
            libtorrent::session_params *session_params = session_params_arg.Get("sessionParams").As<Napi::External<libtorrent::session_params>>().Data();
            this->session = new libtorrent::session(*session_params);
        }
    }
}
Napi::Function Libtorrent::Session::Init(Napi::Env env)
{
    return DefineClass(env, "Session", {
                                           InstanceAccessor<&Session::GetSession, &Session::SetSession>("session"),
                                           InstanceMethod<&Session::IsValid>("isValid"),
                                           InstanceMethod<&Session::PostDhtStats>("postDhtStats"),
                                           InstanceMethod<&Session::PostSessionStats>("postSessionStats"),
                                           InstanceMethod<&Session::PostTorrentUpdates>("postTorrentUpdates"),
                                           InstanceMethod<&Session::DhtSampleInfohashes>("dhtSampleInfohashes"),
                                           InstanceMethod<&Session::PopAlerts>("popAlerts"),
                                       });
}
Napi::Value Libtorrent::Session::GetSession(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::session>::New(env, this->session);
}
void Libtorrent::Session::SetSession(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::session *session = value.As<Napi::External<libtorrent::session>>().Data();
    this->session = session;
}
Napi::Value Libtorrent::Session::IsValid(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Boolean::New(env, this->session->is_valid());
}
Napi::Value Libtorrent::Session::PostDhtStats(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    this->session->post_dht_stats();
    return env.Null();
}
Napi::Value Libtorrent::Session::PostSessionStats(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    this->session->post_session_stats();
    return env.Null();
}
Napi::Value Libtorrent::Session::PostTorrentUpdates(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    this->session->post_torrent_updates();
    return env.Null();
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
Napi::Value Libtorrent::Session::PopAlerts(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::Array alerts_arg = info[0].As<Napi::Array>();
    std::vector<libtorrent::alert *> *alerts = new std::vector<libtorrent::alert *>();
    this->session->pop_alerts(alerts);
    for (libtorrent::alert *alert : *alerts)
    {
        Napi::Object alert_arg = Alert::Init(env).New({});
        alert_arg.Set("alert", Napi::External<libtorrent::alert>::New(env, alert));
        alerts_arg.Set(alerts_arg.Length(), alert_arg);
    }
    return env.Null();
}
