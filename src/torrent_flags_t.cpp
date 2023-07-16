#include "main.hpp"
Libtorrent::TorrentFlagsT::TorrentFlagsT(const Napi::CallbackInfo &info) : Napi::ObjectWrap<TorrentFlagsT>(info)
{
    if (info.Length() < 1)
    {
        this->torrent_flags_t = new libtorrent::torrent_flags_t();
    }
    else
    {
        Napi::Object torrent_flags_t_arg = info[0].As<Napi::Object>();
        libtorrent::torrent_flags_t *torrent_flags_t = torrent_flags_t_arg.Get("torrentFlagsT").As<Napi::External<libtorrent::torrent_flags_t>>().Data();
        this->torrent_flags_t = new libtorrent::torrent_flags_t(*torrent_flags_t);
    }
}
Napi::Function Libtorrent::TorrentFlagsT::Init(Napi::Env env)
{
    return DefineClass(env, "TorrentFlagsT", {
                                            InstanceAccessor<&TorrentFlagsT::GetTorrentFlagsT, &TorrentFlagsT::SetTorrentFlagsT>("torrentFlagsT"),
                                            InstanceMethod<&TorrentFlagsT::OperatorPipeEqual>("operator|="),
                                        });
}
Napi::Value Libtorrent::TorrentFlagsT::GetTorrentFlagsT(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::torrent_flags_t>::New(env, this->torrent_flags_t);
}
void Libtorrent::TorrentFlagsT::SetTorrentFlagsT(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::torrent_flags_t *torrent_flags_t = value.As<Napi::External<libtorrent::torrent_flags_t>>().Data();
    this->torrent_flags_t = torrent_flags_t;
}
Napi::Value Libtorrent::TorrentFlagsT::OperatorPipeEqual(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::Object torrent_flags_t_arg = info[0].As<Napi::Object>();
    libtorrent::torrent_flags_t *torrent_flags_t = torrent_flags_t_arg.Get("torrentFlagsT").As<Napi::External<libtorrent::torrent_flags_t>>().Data();
    libtorrent::torrent_flags_t result = this->torrent_flags_t->operator|=(*torrent_flags_t);
    Napi::Object result_arg = Init(env).New({});
    result_arg.Set("torrentFlagsT", Napi::External<libtorrent::torrent_flags_t>::New(env, new libtorrent::torrent_flags_t(result)));
    return result_arg;
}
