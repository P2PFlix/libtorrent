#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class Sha256Hash : public Napi::ObjectWrap<Sha256Hash>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        Sha256Hash(const Napi::CallbackInfo &info);

    private:
        libtorrent::sha256_hash *sha256_hash;
        Napi::Value GetSha256Hash(const Napi::CallbackInfo &info);
        void SetSha256Hash(const Napi::CallbackInfo &info, const Napi::Value &value);
        Napi::Value Assign(const Napi::CallbackInfo &info);
    };
}
