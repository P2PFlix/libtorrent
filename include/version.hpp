#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    Napi::String Version(const Napi::CallbackInfo &info);
}
