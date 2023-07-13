#include "main.hpp"
Libtorrent::InfoHashT::InfoHashT(const Napi::CallbackInfo &info) : Napi::ObjectWrap<InfoHashT>(info)
{
    if (info.Length() < 1)
    {
        this->info_hash_t = new libtorrent::info_hash_t();
    }
    else
    {
        Napi::Object info_hash_t_arg = info[0].As<Napi::Object>();
        if (info_hash_t_arg.Has("sha1Hash"))
        {
            libtorrent::sha1_hash *sha1_hash = info_hash_t_arg.Get("sha1Hash").As<Napi::External<libtorrent::sha1_hash>>().Data();
            this->info_hash_t = new libtorrent::info_hash_t(*sha1_hash);
        }
        else
        {
            libtorrent::info_hash_t *info_hash_t = info_hash_t_arg.Get("infoHashT").As<Napi::External<libtorrent::info_hash_t>>().Data();
            this->info_hash_t = new libtorrent::info_hash_t(*info_hash_t);
        }
    }
}
Napi::Function Libtorrent::InfoHashT::Init(Napi::Env env)
{
    return DefineClass(env, "InfoHashT", {
                                             InstanceAccessor<&InfoHashT::GetInfoHashT, &InfoHashT::SetInfoHashT>("infoHashT"),
                                         });
}
Napi::Value Libtorrent::InfoHashT::GetInfoHashT(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::info_hash_t>::New(env, this->info_hash_t);
}
void Libtorrent::InfoHashT::SetInfoHashT(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::info_hash_t *info_hash_t = value.As<Napi::External<libtorrent::info_hash_t>>().Data();
    this->info_hash_t = info_hash_t;
}
