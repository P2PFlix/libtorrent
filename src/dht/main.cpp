#include "main.hpp"
Napi::Object Libtorrent::Dht::Init(Napi::Env env)
{
    Napi::Object dht = Napi::Object::New(env);
    dht.Set("DhtState", DhtState::Init(env));
    return dht;
}
