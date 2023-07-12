#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class TorrentHandle : public Napi::ObjectWrap<TorrentHandle>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        TorrentHandle(const Napi::CallbackInfo &info);

    private:
        libtorrent::torrent_handle *torrent_handle;
        Napi::Value GetTorrentHandle(const Napi::CallbackInfo &info);
        void SetTorrentHandle(const Napi::CallbackInfo &info, const Napi::Value &value);
    };
}
