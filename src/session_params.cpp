#include "main.hpp"
Libtorrent::SessionParams::SessionParams(const Napi::CallbackInfo &info) : Napi::ObjectWrap<SessionParams>(info)
{
    if (info.Length() < 1)
    {
        this->session_params = new libtorrent::session_params();
    }
    else
    {
        Napi::Object settings_pack_arg = info[0].As<Napi::Object>();
        if (settings_pack_arg.Has("sessionParams"))
        {
            libtorrent::session_params *session_params = settings_pack_arg.Get("sessionParams").As<Napi::External<libtorrent::session_params>>().Data();
            this->session_params = new libtorrent::session_params(*session_params);
        }
        else
        {
            libtorrent::settings_pack *settings_pack = settings_pack_arg.Get("settingsPack").As<Napi::External<libtorrent::settings_pack>>().Data();
            this->session_params = new libtorrent::session_params(*settings_pack);
        }
    }
}
Napi::Function Libtorrent::SessionParams::Init(Napi::Env env)
{
    return DefineClass(env, "SessionParams", {
                                                 InstanceAccessor<&SessionParams::GetSessionParams, &SessionParams::SetSessionParams>("sessionParams"),
                                                 InstanceAccessor<&SessionParams::GetDhtState>("dhtState"),
                                             });
}
Napi::Value Libtorrent::SessionParams::GetSessionParams(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::session_params>::New(env, this->session_params);
}
void Libtorrent::SessionParams::SetSessionParams(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::session_params *session_params = value.As<Napi::External<libtorrent::session_params>>().Data();
    this->session_params = session_params;
}
Napi::Value Libtorrent::SessionParams::GetDhtState(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    libtorrent::dht::dht_state dht_state = this->session_params->dht_state;
    Napi::Object dht_state_arg = Dht::DhtState::Init(env).New({});
    dht_state_arg.Set("dhtState", Napi::External<libtorrent::dht::dht_state>::New(env, new libtorrent::dht::dht_state(dht_state)));
    return dht_state_arg;
}
