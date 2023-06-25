#pragma once
#include "napi.h"
#include "libtorrent/libtorrent.hpp"
namespace Libtorrent
{
    Napi::External<boost::asio::ip::address> MakeAddress(const Napi::CallbackInfo &info);
}
