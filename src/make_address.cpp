#include "make_address.hpp"
Napi::External<boost::asio::ip::address> Libtorrent::MakeAddress(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    boost::asio::ip::address *address = new boost::asio::ip::address(libtorrent::make_address(info[0].As<Napi::String>().Utf8Value()));
    return Napi::External<boost::asio::ip::address>::New(env, address);
};
