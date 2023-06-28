#include "main.hpp"
Napi::Object Libtorrent::Udp::Init(Napi::Env env)
{
    Napi::Object udp = Napi::Object::New(env);
    udp.Set("Endpoint", Endpoint::Init(env));
    return udp;
}
