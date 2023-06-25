#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class Session : public Napi::ObjectWrap<Session>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        Session(const Napi::CallbackInfo &info);

    private:
        libtorrent::session *session;
        Napi::Value IsValid(const Napi::CallbackInfo &info);
        Napi::Value DhtSampleInfohashes(const Napi::CallbackInfo &info);
    };
}
