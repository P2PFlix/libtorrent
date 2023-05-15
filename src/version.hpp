#ifndef LIBTORRENT_NODE_VERSION_H
#define LIBTORRENT_NODE_VERSION_H

#include <napi.h>
#include <libtorrent/session.hpp>

namespace LibtorrentNode
{
    /**
     * @brief Get the Lib Torrent Version object
     * 
     * @param info 
     * @return Napi::String 
     */
    Napi::String getLibTorrentVersion(const Napi::CallbackInfo &info);

    /**
     * @brief NodeJS N-API init function, to be later called in InitAll()
     * 
     * @param env 
     * @param exports 
     * @return Napi::Object 
     */
    Napi::Object Init(Napi::Env env, Napi::Object& exports);
}

#endif