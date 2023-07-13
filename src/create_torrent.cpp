#include "main.hpp"
Libtorrent::CreateTorrent::CreateTorrent(const Napi::CallbackInfo &info) : Napi::ObjectWrap<CreateTorrent>(info)
{
    if (info.Length() < 1)
    {
        this->create_torrent = nullptr;
    }
    else
    {
        Napi::Object create_torrent_arg = info[0].As<Napi::Object>();
        libtorrent::create_torrent *create_torrent = create_torrent_arg.Get("createTorrent").As<Napi::External<libtorrent::create_torrent>>().Data();
        this->create_torrent = new libtorrent::create_torrent(*create_torrent);
    }
}
Napi::Function Libtorrent::CreateTorrent::Init(Napi::Env env)
{
    return DefineClass(env, "CreateTorrent", {
                                                 InstanceAccessor<&CreateTorrent::GetCreateTorrent, &CreateTorrent::SetCreateTorrent>("createTorrent"),
                                             });
}
Napi::Value Libtorrent::CreateTorrent::GetCreateTorrent(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::create_torrent>::New(env, this->create_torrent);
}
void Libtorrent::CreateTorrent::SetCreateTorrent(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::create_torrent *create_torrent = value.As<Napi::External<libtorrent::create_torrent>>().Data();
    this->create_torrent = create_torrent;
}
