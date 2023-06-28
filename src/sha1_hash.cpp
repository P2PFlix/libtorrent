#include "main.hpp"
Libtorrent::Sha1Hash::Sha1Hash(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Sha1Hash>(info)
{
    if (info.Length() < 1)
    {
        this->sha1_hash = new libtorrent::sha1_hash();
    }
    else
    {
        Napi::Object sha1_hash_arg = info[0].As<Napi::Object>();
        libtorrent::sha1_hash *sha1_hash = sha1_hash_arg.Get("sha1Hash").As<Napi::External<libtorrent::sha1_hash>>().Data();
        this->sha1_hash = new libtorrent::sha1_hash(*sha1_hash);
    }
}
Napi::Function Libtorrent::Sha1Hash::Init(Napi::Env env)
{
    return DefineClass(env, "Sha1Hash", {
                                            InstanceAccessor<&Sha1Hash::GetSha1Hash, &Sha1Hash::SetSha1Hash>("sha1Hash"),
                                            InstanceMethod<&Sha1Hash::Assign>("assign"),
                                        });
}
Napi::Value Libtorrent::Sha1Hash::GetSha1Hash(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::sha1_hash>::New(env, this->sha1_hash);
}
void Libtorrent::Sha1Hash::SetSha1Hash(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::sha1_hash *sha1_hash = value.As<Napi::External<libtorrent::sha1_hash>>().Data();
    this->sha1_hash = sha1_hash;
}
Napi::Value Libtorrent::Sha1Hash::Assign(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    char *hex = info[0].As<Napi::Buffer<char>>().Data();
    this->sha1_hash->assign(hex);
    return env.Null();
}
