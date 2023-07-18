#include "main.hpp"
Libtorrent::Sha256Hash::Sha256Hash(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Sha256Hash>(info)
{
    if (info.Length() < 1)
    {
        this->sha256_hash = new libtorrent::sha256_hash();
    }
    else
    {
        if (info[0].IsBuffer())
        {
            Napi::Buffer hex = info[0].As<Napi::Buffer<char>>();
            this->sha256_hash = new libtorrent::sha256_hash(hex.Data());
        }
        else
        {
            Napi::Object sha256_hash_arg = info[0].As<Napi::Object>();
            libtorrent::sha256_hash *sha256_hash = sha256_hash_arg.Get("sha256Hash").As<Napi::External<libtorrent::sha256_hash>>().Data();
            this->sha256_hash = new libtorrent::sha256_hash(*sha256_hash);
        }
    }
}
Napi::Function Libtorrent::Sha256Hash::Init(Napi::Env env)
{
    return DefineClass(env, "Sha256Hash", {
                                              InstanceAccessor<&Sha256Hash::GetSha256Hash, &Sha256Hash::SetSha256Hash>("sha256Hash"),
                                              InstanceMethod<&Sha256Hash::Assign>("assign"),
                                          });
}
Napi::Value Libtorrent::Sha256Hash::GetSha256Hash(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::sha256_hash>::New(env, this->sha256_hash);
}
void Libtorrent::Sha256Hash::SetSha256Hash(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::sha256_hash *sha256_hash = value.As<Napi::External<libtorrent::sha256_hash>>().Data();
    this->sha256_hash = sha256_hash;
}
Napi::Value Libtorrent::Sha256Hash::Assign(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::Buffer hex = info[0].As<Napi::Buffer<char>>();
    this->sha256_hash->assign(hex.Data());
    return env.Null();
}
