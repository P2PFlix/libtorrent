#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    namespace Udp
    {
        class Endpoint : public Napi::ObjectWrap<Endpoint>
        {
        public:
            static Napi::Function Init(Napi::Env env);
            Endpoint(const Napi::CallbackInfo &info);
            void SetEndpoint(const Napi::CallbackInfo &info, const Napi::Value &value);

        private:
            libtorrent::udp::endpoint *endpoint;
            Napi::Value GetEndpoint(const Napi::CallbackInfo &info);
            Napi::Value Port(const Napi::CallbackInfo &info);
            Napi::Value Address(const Napi::CallbackInfo &info);
        };
    }
}
