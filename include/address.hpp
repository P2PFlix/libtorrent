#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
        class Address : public Napi::ObjectWrap<Address>
        {
        public:
            static Napi::Function Init(Napi::Env env);
            Address(const Napi::CallbackInfo &info);

        private:
            libtorrent::address *address;
            Napi::Value GetAddress(const Napi::CallbackInfo &info);
            void SetAddress(const Napi::CallbackInfo &info, const Napi::Value &value);
        };
}
