#include "main.hpp"
Napi::Object Libtorrent::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("version", Napi::Function::New(env, Version));
    exports.Set("makeAddress", Napi::Function::New(env, MakeAddress));
    exports.Set("SettingsPack", SettingsPack::Init(env));
    exports.Set("SessionParams", SessionParams::Init(env));
    exports.Set("Session", Session::Init(env));
    exports.Set("Alert", Alert::Init(env));
    exports.Set("DhtSampleInfohashesAlert", DhtSampleInfohashesAlert::Init(env));
    exports.Set("MetadataReceivedAlert", MetadataReceivedAlert::Init(env));
    exports.Set("Address", Address::Init(env));
    exports.Set("Sha1Hash", Sha1Hash::Init(env));
    exports.Set("Sha256Hash", Sha256Hash::Init(env));
    exports.Set("AddTorrentParams", AddTorrentParams::Init(env));
    exports.Set("InfoHashT", InfoHashT::Init(env));
    exports.Set("TorrentFlagsT", TorrentFlagsT::Init(env));
    exports.Set("TorrentHandle", TorrentHandle::Init(env));
    exports.Set("CreateTorrent", TorrentHandle::Init(env));
    exports.Set("IovecT", IovecT::Init(env));
    exports.Set("TorrentInfo", TorrentInfo::Init(env));
    exports.Set("udp", Udp::Init(env));
    exports.Set("dht", Dht::Init(env));
    exports.Set("torrentFlags", TorrentFlags::Init(env));
    return exports;
}
namespace Libtorrent
{
    NODE_API_MODULE(LIBTORRENT, Init)
}
