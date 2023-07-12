#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    class CreateTorrent : public Napi::ObjectWrap<CreateTorrent>
    {
    public:
        static Napi::Function Init(Napi::Env env);
        CreateTorrent(const Napi::CallbackInfo &info);

    private:
        libtorrent::create_torrent *create_torrent;
        Napi::Value GetCreateTorrent(const Napi::CallbackInfo &info);
        void SetCreateTorrent(const Napi::CallbackInfo &info, const Napi::Value &value);
    };
}
