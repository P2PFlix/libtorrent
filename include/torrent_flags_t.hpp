#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class TorrentFlagsT : public Napi::ObjectWrap<TorrentFlagsT>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        TorrentFlagsT(const Napi::CallbackInfo &info);

    private:
        libtorrent::torrent_flags_t *torrent_flags_t;
        Napi::Value GetTorrentFlagsT(const Napi::CallbackInfo &info);
        void SetTorrentFlagsT(const Napi::CallbackInfo &info, const Napi::Value &value);
        Napi::Value OperatorPipeEqual(const Napi::CallbackInfo &info);
    };
}
