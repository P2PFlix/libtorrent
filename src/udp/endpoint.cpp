#include "main.hpp"
Libtorrent::Udp::Endpoint::Endpoint(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Endpoint>(info)
{
    if (info.Length() < 1)
    {
        this->endpoint = new libtorrent::udp::endpoint();
    }
    else
    {
        Napi::Object endpoint_arg = info[0].As<Napi::Object>();
        libtorrent::udp::endpoint *endpoint = endpoint_arg.Get("endpoint").As<Napi::External<libtorrent::udp::endpoint>>().Data();
        this->endpoint = new libtorrent::udp::endpoint(*endpoint);
    }
}
Napi::Function Libtorrent::Udp::Endpoint::Init(Napi::Env env)
{
    return DefineClass(env, "Endpoint", {
                                            InstanceAccessor<&Endpoint::GetEndpoint, &Endpoint::SetEndpoint>("endpoint"),
                                            InstanceMethod<&Endpoint::Port>("port"),
                                            InstanceMethod<&Endpoint::Address>("address"),
                                        });
}
Napi::Value Libtorrent::Udp::Endpoint::GetEndpoint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::udp::endpoint>::New(env, this->endpoint);
}
void Libtorrent::Udp::Endpoint::SetEndpoint(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::udp::endpoint *endpoint = value.As<Napi::External<libtorrent::udp::endpoint>>().Data();
    this->endpoint = endpoint;
}
Napi::Value Libtorrent::Udp::Endpoint::Port(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int port = info[0].As<Napi::Number>().Int64Value();
    this->endpoint->port(port);
    return env.Null();
}
Napi::Value Libtorrent::Udp::Endpoint::Address(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    boost::asio::ip::address *address = info[0].As<Napi::External<boost::asio::ip::address>>().Data();
    this->endpoint->address(*address);
    return env.Null();
}
