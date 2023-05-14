#ifndef BINDINGS_H
#define BINDINGS_H

#include <napi.h>
#include <libtorrent/magnet_uri.hpp>
#include <libtorrent/session.hpp>

namespace LibtorrentNode
{
    lt::torrent_handle _torrent;
    Napi::String Version(const Napi::CallbackInfo &info);
    lt::torrent_handle findTorrent(lt::session *session, std::uint32_t to_find_id);

    class Torrent : public Napi::ObjectWrap<Torrent>
    {
    public:
        Napi::Object obj;
        Torrent(const Napi::CallbackInfo &info);
        inline static Napi::Object NewInstance(Napi::Env env, lt::torrent_handle torrent);
        inline static Napi::Object Init(Napi::Env env, Napi::Object exports);

        Napi::Value Pause(const Napi::CallbackInfo &info);
        Napi::Value Resume(const Napi::CallbackInfo &info);
        Napi::Value SetLimit(const Napi::CallbackInfo &info);
        Napi::Value GetFiles(const Napi::CallbackInfo &info);
        Napi::Value Info(const Napi::CallbackInfo &info);

    private:
        inline static Napi::FunctionReference constructor;
        lt::torrent_handle torrent;
    };

    class Client : public Napi::ObjectWrap<Client>
    {
    public:
        inline static Napi::Object Init(Napi::Env env, Napi::Object exports);
        Client(const Napi::CallbackInfo &info);

    private:
        inline static Napi::FunctionReference constructor;
        lt::session session;
        lt::session_proxy session_proxy;

        Napi::Value AddTorrent(const Napi::CallbackInfo &info);
        Napi::Value RemoveTorrent(const Napi::CallbackInfo &info);
        Napi::Value GetTorrents(const Napi::CallbackInfo &info);
        Napi::Value GetTorrent(const Napi::CallbackInfo &info);
        Napi::Value GetClientInfo(const Napi::CallbackInfo &info);
        Napi::Value HasTorrents(const Napi::CallbackInfo &info);
        Napi::Value IsDestroyed(const Napi::CallbackInfo &info);
    };
    // inline extern
    // inline extern
    // Napi::Object Init(Napi::Env env, Napi::Object exports);
    // NODE_API_MODULE(LIBTORRENT_NODE, Init)
}

#endif