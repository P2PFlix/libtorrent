#include "main.hpp"
Libtorrent::SessionParams::SessionParams(const Napi::CallbackInfo &info) : Napi::ObjectWrap<SessionParams>(info)
{
    if (info.Length() < 1)
    {
        this->session_params = new libtorrent::session_params();
    }
    else
    {
        Napi::Object session_params_arg = info[0].As<Napi::Object>();
        if (session_params_arg.Has("settingsPack"))
        {
            libtorrent::settings_pack *settings_pack = session_params_arg.Get("settingsPack").As<Napi::External<libtorrent::settings_pack>>().Data();
            this->session_params = new libtorrent::session_params(*settings_pack);
        }
        else
        {
            libtorrent::session_params *session_params = session_params_arg.Get("sessionParams").As<Napi::External<libtorrent::session_params>>().Data();
            this->session_params = new libtorrent::session_params(*session_params);
        }
    }
}
Napi::Function Libtorrent::SessionParams::Init(Napi::Env env)
{
    return DefineClass(env, "SessionParams", {
                                                 InstanceAccessor<&SessionParams::GetSessionParams, &SessionParams::SetSessionParams>("sessionParams"),
                                                 InstanceAccessor<&SessionParams::GetDhtState, &SessionParams::SetDhtState>("dhtState"),
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
void Libtorrent::SessionParams::SetDhtState(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    Napi::Object dht_state_arg = value.As<Napi::Object>();
    libtorrent::dht::dht_state *dht_state = dht_state_arg.Get("dhtState").As<Napi::External<libtorrent::dht::dht_state>>().Data();
    this->session_params->dht_state = *dht_state;
}
