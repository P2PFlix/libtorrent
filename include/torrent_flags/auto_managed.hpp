#pragma once
#include "napi.h"
namespace Libtorrent
{
    namespace TorrentFlags
    {
        Napi::Object AutoManaged(Napi::Env env);
    }
}
