#include "main.hpp"
Napi::Object Libtorrent::MakeAddress(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    libtorrent::address address = libtorrent::make_address(info[0].As<Napi::String>().Utf8Value());
    Napi::Object address_arg = Address::Init(env).New({});
    address_arg.Set("address", Napi::External<libtorrent::address>::New(env, new libtorrent::address(address)));
    return address_arg;
};
