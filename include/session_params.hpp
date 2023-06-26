#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class SessionParams : public Napi::ObjectWrap<SessionParams>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        SessionParams(const Napi::CallbackInfo &info);

    private:
        libtorrent::session_params *session_params;
        Napi::Value GetSessionParams(const Napi::CallbackInfo &info);
        void SetSessionParams(const Napi::CallbackInfo &info, const Napi::Value &value);
    };
}
