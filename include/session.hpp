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
        Napi::Value GetSession(const Napi::CallbackInfo &info);
        void SetSession(const Napi::CallbackInfo &info, const Napi::Value &value);
        Napi::Value IsValid(const Napi::CallbackInfo &info);
        Napi::Value PostDhtStats(const Napi::CallbackInfo &info);
        Napi::Value PostSessionStats(const Napi::CallbackInfo &info);
        Napi::Value PostTorrentUpdates(const Napi::CallbackInfo &info);
        Napi::Value DhtSampleInfohashes(const Napi::CallbackInfo &info);
        Napi::Value PopAlerts(const Napi::CallbackInfo &info);
        Napi::Value SessionState(const Napi::CallbackInfo &info);
        Napi::Value AddTorrent(const Napi::CallbackInfo &info);
        Napi::Value AsyncAddTorrent(const Napi::CallbackInfo &info);
    };
}
