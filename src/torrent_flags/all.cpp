#include "main.hpp"
Napi::Object Libtorrent::TorrentFlags::All(Napi::Env env)
{
    libtorrent::torrent_flags_t *torrent_flags_t = new libtorrent::torrent_flags_t(libtorrent::torrent_flags::all);
    Napi::Object torrent_flags_t_arg = TorrentFlagsT::Init(env).New({});
    torrent_flags_t_arg.Set("torrentFlagsT", Napi::External<libtorrent::torrent_flags_t>::New(env, torrent_flags_t));
    return torrent_flags_t_arg;
}
