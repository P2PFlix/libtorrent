#pragma once
#include "napi.h"
namespace Libtorrent
{
    namespace TorrentFlags
    {
        Napi::Object DefaultFlags(Napi::Env env);
    }
}
