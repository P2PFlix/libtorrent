#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class AddTorrentParams : public Napi::ObjectWrap<AddTorrentParams>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        AddTorrentParams(const Napi::CallbackInfo &info);

    private:
        libtorrent::add_torrent_params *add_torrent_params;
        Napi::Value GetAddTorrentParams(const Napi::CallbackInfo &info);
        void SetAddTorrentParams(const Napi::CallbackInfo &info, const Napi::Value &value);
        Napi::Value GetFlags(const Napi::CallbackInfo &info);
        void SetFlags(const Napi::CallbackInfo &info, const Napi::Value &value);
        Napi::Value GetInfoHashes(const Napi::CallbackInfo &info);
        void SetInfoHashes(const Napi::CallbackInfo &info, const Napi::Value &value);
    };
}
