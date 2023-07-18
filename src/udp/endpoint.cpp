#include "main.hpp"
Libtorrent::Udp::Endpoint::Endpoint(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Endpoint>(info)
{
    if (info.Length() < 1)
    {
        this->endpoint = new libtorrent::udp::endpoint();
    }
    else if (info.Length() < 2)
    {
        Napi::Object endpoint_arg = info[0].As<Napi::Object>();
        libtorrent::udp::endpoint *endpoint = endpoint_arg.Get("endpoint").As<Napi::External<libtorrent::udp::endpoint>>().Data();
        this->endpoint = new libtorrent::udp::endpoint(*endpoint);
    }
    else
    {
        Napi::Object address_arg = info[0].As<Napi::Object>();
        libtorrent::address *address = address_arg.Get("address").As<Napi::External<libtorrent::address>>().Data();
        int port = info[1].As<Napi::Number>().Int64Value();
        this->endpoint = new libtorrent::udp::endpoint(*address, port);
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
    if (info.Length() < 1)
    {
        return Napi::Number::New(env, this->endpoint->port());
    }
    int port = info[0].As<Napi::Number>().Int64Value();
    this->endpoint->port(port);
    return env.Null();
}
Napi::Value Libtorrent::Udp::Endpoint::Address(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::Object address_arg = Address::Init(env).New({});
        address_arg.Set("address", Napi::External<libtorrent::address>::New(env, new libtorrent::address(this->endpoint->address())));
        return address_arg;
    }
    Napi::Object address_arg = info[0].As<Napi::Object>();
    libtorrent::address *address = address_arg.Get("address").As<Napi::External<libtorrent::address>>().Data();
    this->endpoint->address(*address);
    return env.Null();
}
