#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class InfoHashT : public Napi::ObjectWrap<InfoHashT>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        InfoHashT(const Napi::CallbackInfo &info);

    private:
        libtorrent::info_hash_t *info_hash_t;
        Napi::Value GetInfoHashT(const Napi::CallbackInfo &info);
        void SetInfoHashT(const Napi::CallbackInfo &info, const Napi::Value &value);
        Napi::Value GetV1(const Napi::CallbackInfo &info);
        void SetV1(const Napi::CallbackInfo &info, const Napi::Value &value);
        Napi::Value GetV2(const Napi::CallbackInfo &info);
        void SetV2(const Napi::CallbackInfo &info, const Napi::Value &value);
    };
}
