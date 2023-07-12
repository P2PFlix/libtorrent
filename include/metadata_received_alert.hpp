#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
        class MetadataReceivedAlert : public Napi::ObjectWrap<MetadataReceivedAlert>
        {
        public:
            static Napi::Function Init(Napi::Env env);
            MetadataReceivedAlert(const Napi::CallbackInfo &info);

        private:
            libtorrent::metadata_received_alert *metadata_received_alert;
            Napi::Value GetMetadataReceivedAlert(const Napi::CallbackInfo &info);
            void SetMetadataReceivedAlert(const Napi::CallbackInfo &info, const Napi::Value &value);
        };
}
