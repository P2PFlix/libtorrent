#pragma once
#include "torrent_flags/default_dont_download.hpp"
#include "torrent_flags/all.hpp"
#include "torrent_flags/auto_managed.hpp"
#include "torrent_flags/default_flags.hpp"
namespace Libtorrent
{
    namespace TorrentFlags
    {
        Napi::Object Init(Napi::Env env);
    }
}
