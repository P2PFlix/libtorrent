#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class Alert : public Napi::ObjectWrap<Alert>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        Alert(const Napi::CallbackInfo &info);

    private:
        libtorrent::alert *alert;
        Napi::Value GetAlert(const Napi::CallbackInfo &info);
        void SetAlert(const Napi::CallbackInfo &info, const Napi::Value &value);
    };
}
