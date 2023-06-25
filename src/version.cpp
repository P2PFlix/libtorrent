#include "version.hpp"
Napi::String Libtorrent::Version(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::String::New(env, libtorrent::version());
};
