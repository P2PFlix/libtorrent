#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class TorrentInfo : public Napi::ObjectWrap<TorrentInfo>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        TorrentInfo(const Napi::CallbackInfo &info);

    private:
        libtorrent::torrent_info *torrent_info;
        Napi::Value GetTorrentInfo(const Napi::CallbackInfo &info);
        void SetTorrentInfo(const Napi::CallbackInfo &info, const Napi::Value &value);
        Napi::Value InfoSection(const Napi::CallbackInfo &info);
    };
}
