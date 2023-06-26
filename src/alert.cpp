#include "alert.hpp"
Libtorrent::Alert::Alert(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Alert>(info)
{
    this->alert = nullptr;
}
Napi::Function Libtorrent::Alert::Init(Napi::Env env)
{
    return DefineClass(env, "Alert", {
                                         InstanceAccessor<&Alert::GetAlert, &Alert::SetAlert>("alert"),
                                         InstanceMethod<&Alert::Type>("type"),
                                     });
}
void Libtorrent::Alert::SetAlert(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::alert *alert = value.As<Napi::External<libtorrent::alert>>().Data();
    this->alert = alert;
}
Napi::Value Libtorrent::Alert::GetAlert(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::alert>::New(env, this->alert);
}
Napi::Value Libtorrent::Alert::Type(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->alert->type());
}
