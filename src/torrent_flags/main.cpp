#include "main.hpp"
Napi::Object Libtorrent::TorrentFlags::Init(Napi::Env env)
{
    Napi::Object torrentFlags = Napi::Object::New(env);
    torrentFlags.Set("defaultDontDownload", DefaultDontDownload(env));
    torrentFlags.Set("all", All(env));
    torrentFlags.Set("autoManaged", AutoManaged(env));
    torrentFlags.Set("defaultFlags", DefaultFlags(env));
    return torrentFlags;
}
