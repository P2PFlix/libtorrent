#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class IovecT : public Napi::ObjectWrap<IovecT>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        IovecT(const Napi::CallbackInfo &info);

    private:
        libtorrent::iovec_t *iovec_t;
        Napi::Value GetIovecT(const Napi::CallbackInfo &info);
        void SetIovecT(const Napi::CallbackInfo &info, const Napi::Value &value);
        Napi::Value Data(const Napi::CallbackInfo &info);
    };
}
