#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    namespace Dht
    {
        class DhtState : public Napi::ObjectWrap<DhtState>
        {
        public:
            static Napi::Function Init(Napi::Env env);
            DhtState(const Napi::CallbackInfo &info);

        private:
            libtorrent::dht::dht_state *dht_state;
            Napi::Value GetDhtState(const Napi::CallbackInfo &info);
            void SetDhtState(const Napi::CallbackInfo &info, const Napi::Value &value);
            Napi::Value GetNodes(const Napi::CallbackInfo &info);
        };
    }
}
