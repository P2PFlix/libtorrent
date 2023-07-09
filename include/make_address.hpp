#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    Napi::External<libtorrent::address> MakeAddress(const Napi::CallbackInfo &info);
}
