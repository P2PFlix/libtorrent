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

        /**
         * @brief This function is called in the Node.JS runtime on an object of class Client and will
         * return true if, using the values passed as parameters, it is able to add a new torrent to the 
         * session, maintained by the Client. If successful, the function returns the id of the added torrent.
         * The added torrent will also start downloading and the files will appear at the path provided
         * It throws an Exception if the arguments supplied are incorrect.
         * 
         * JS Usage: 
         * const client = new Client();
         * client.addTorrent(fileSavePath: string, magnet: string);
         *
         * @param info
         * @return Napi::Value
         */
        Napi::Value AddTorrent(const Napi::CallbackInfo &info);

        /**
         * @brief This function is called in the Node.JS runtime on an object of class Client and will
         * return true if, using the values passed as parameters, it is able to remove an existing torrent
         * that was previously added to the Client object in question. If successful, the function returns
         * true. If the torrent id supplied is not present / not valid, nothing happens.
         * It throws an Exception if the arguments supplied are incorrect.
         *
         * JS Usage:
         * const client = new Client();
         * client.removeTorrent(fileSavePath: string, magnet: string);
         *
         * @param info
         * @return Napi::Value
         */
        Napi::Value RemoveTorrent(const Napi::CallbackInfo &info);

        /**
         * @brief This function is called in the Node.JS runtime on an object of class Client and will
         * return (in the Node.JS runtime) an array of Torrent objects contained in the client's session.
         * (see Ts bindings for more details). This function does not require any arguments when called 
         * in a Node.JS environment.
         * 
         * JS Usage:
         * const client = new Client();
         * client.removeTorrent();
         * 
         *
         * @param info
         * @return Napi::Value
         */
        Napi::Value GetTorrents(const Napi::CallbackInfo &info);

        /**
         * @brief This function is called in the Node.JS runtime on an object of class Client and will
         * return (in the Node.JS runtime) a Torrent object using the id provided as an argument when 
         * calling the function. If no torrent is found, it returns a torrent handle that does not 
         * point to any torrent. It throws an Exception if incorrect arguments are passed.
         * 
         * JS Usage:
         * const client = new Client();
         * client.getTorrent(id: number);
         *
         * @param info
         * @return Napi::Value
         */
        Napi::Value GetTorrent(const Napi::CallbackInfo &info);

        /**
         * @brief This function is called in the Node.JS runtime on an object of class Client and will
         * return (in the Node.JS runtime) an object of type GetClientInfoReturnModel (see Typescript binding types
         * for more details). It does not take any arguments.
         * 
         * JS Usage:
         * const client = new Client();
         * client.getClientInfo();
         *
         * @param info
         * @return Napi::Value
         */
        Napi::Value GetClientInfo(const Napi::CallbackInfo &info);

        /**
         * @brief This function is called in the Node.JS runtime on an object of class Client and will
         * return (in the Node.JS runtime) a boolean if the client has torrents added, either in the downloading,
         * downloaded or paused state. It does not take any arguments.
         * 
         * JS Usage:
         * const client =  new Client();
         * client.hasTorrents();
         *
         * @param info
         * @return Napi::Value
         */
        Napi::Value HasTorrents(const Napi::CallbackInfo &info);

        /**
         * @brief This function is called in the Node.JS runtime on an object of class Client and will
         * return true if the client represented by the object has been destroyed.
         * Else it will throw an Exception upon failure.
         *
         * @param info
         * @return Napi::Value
         */
        Napi::Value IsDestroyed(const Napi::CallbackInfo &info);
    };
    // inline extern
    // inline extern
    // Napi::Object Init(Napi::Env env, Napi::Object exports);
    // NODE_API_MODULE(LIBTORRENT_NODE, Init)
}

#endif