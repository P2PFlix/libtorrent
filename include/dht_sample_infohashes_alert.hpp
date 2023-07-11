#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
        class DhtSampleInfohashesAlert : public Napi::ObjectWrap<DhtSampleInfohashesAlert>
        {
        public:
            static Napi::Function Init(Napi::Env env);
            DhtSampleInfohashesAlert(const Napi::CallbackInfo &info);

        private:
            libtorrent::dht_sample_infohashes_alert *dht_sample_infohashes_alert;
            Napi::Value GetDhtSampleInfohashesAlert(const Napi::CallbackInfo &info);
            void SetDhtSampleInfohashesAlert(const Napi::CallbackInfo &info, const Napi::Value &value);
            Napi::Value Samples(const Napi::CallbackInfo &info);
        };
}
