#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp" // TODO
namespace Libtorrent
{
    Napi::String Version(const Napi::CallbackInfo &info);
}
