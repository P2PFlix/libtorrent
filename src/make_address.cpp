#include "main.hpp"
Napi::External<libtorrent::address> Libtorrent::MakeAddress(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    libtorrent::address *address = new libtorrent::address(libtorrent::make_address(info[0].As<Napi::String>().Utf8Value()));
    return Napi::External<libtorrent::address>::New(env, address);
};
