#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class Sha1Hash : public Napi::ObjectWrap<Sha1Hash>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        Sha1Hash(const Napi::CallbackInfo &info);

    private:
        libtorrent::sha1_hash *sha1_hash;
        Napi::Value GetSha1Hash(const Napi::CallbackInfo &info);
        Napi::Value Assign(const Napi::CallbackInfo &info);
    };
}
