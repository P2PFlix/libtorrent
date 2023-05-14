#ifndef LIBTORRENT_NODE_VERSION_H
#define LIBTORRENT_NODE_VERSION_H

#include <napi.h>
#include <libtorrent/session.hpp>

namespace LibtorrentNode
{
    Napi::String getLibTorrentVersion(const Napi::CallbackInfo &info);
    Napi::Object Init(Napi::Env env, Napi::Object& exports);
}

#endif