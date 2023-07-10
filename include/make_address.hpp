#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    Napi::Object MakeAddress(const Napi::CallbackInfo &info);
}
