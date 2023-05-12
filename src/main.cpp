#include "main.hpp"

Napi::String Version(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, lt::version());
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "version"), Napi::Function::New(env, Version));
  return exports;
}

NODE_API_MODULE(LIBTORRENT_NODE, Init)
