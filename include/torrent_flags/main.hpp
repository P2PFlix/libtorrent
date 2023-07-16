#pragma once
#include "torrent_flags/default_dont_download.hpp"
#include "torrent_flags/all.hpp"
namespace Libtorrent
{
    namespace TorrentFlags
    {
        Napi::Object Init(Napi::Env env);
    }
}
