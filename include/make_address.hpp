#pragma once
#include "napi.h"
namespace Libtorrent
{
    Napi::Object MakeAddress(const Napi::CallbackInfo &info);
}
