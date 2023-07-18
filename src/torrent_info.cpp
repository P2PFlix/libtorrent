#include "main.hpp"
Libtorrent::TorrentInfo::TorrentInfo(const Napi::CallbackInfo &info) : Napi::ObjectWrap<TorrentInfo>(info)
{
    if (info.Length() < 1)
    {
        this->torrent_info = nullptr;
    }
    else
    {
        Napi::Object torrent_info_arg = info[0].As<Napi::Object>();
        libtorrent::torrent_info *torrent_info = torrent_info_arg.Get("torrentInfo").As<Napi::External<libtorrent::torrent_info>>().Data();
        this->torrent_info = new libtorrent::torrent_info(*torrent_info);
    }
}
Napi::Function Libtorrent::TorrentInfo::Init(Napi::Env env)
{
    return DefineClass(env, "TorrentInfo", {
                                               InstanceAccessor<&TorrentInfo::GetTorrentInfo, &TorrentInfo::SetTorrentInfo>("torrentInfo"),
                                               InstanceMethod<&TorrentInfo::InfoSection>("infoSection"),
                                           });
}
Napi::Value Libtorrent::TorrentInfo::GetTorrentInfo(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::torrent_info>::New(env, this->torrent_info);
}
void Libtorrent::TorrentInfo::SetTorrentInfo(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::torrent_info *torrent_info = value.As<Napi::External<libtorrent::torrent_info>>().Data();
    this->torrent_info = torrent_info;
}
Napi::Value Libtorrent::TorrentInfo::InfoSection(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    libtorrent::span<const char> span = this->torrent_info->info_section();
    Napi::Object iovec_t_arg = IovecT::Init(env).New({});
    iovec_t_arg.Set("iovecT", Napi::External<libtorrent::iovec_t>::New(env, new libtorrent::iovec_t(const_cast<char *>(span.data()), span.size())));
    return iovec_t_arg;
}
