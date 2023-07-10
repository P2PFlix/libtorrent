#include "main.hpp"
Libtorrent::Address::Address(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Address>(info)
{
    if (info.Length() < 1)
    {
        this->address = new libtorrent::address();
    }
    else
    {
        Napi::Object address_arg = info[0].As<Napi::Object>();
        libtorrent::address *address = address_arg.Get("address").As<Napi::External<libtorrent::address>>().Data();
        this->address = new libtorrent::address(*address);
    }
}
Napi::Function Libtorrent::Address::Init(Napi::Env env)
{
    return DefineClass(env, "Address", {
                                            InstanceAccessor<&Address::GetAddress, &Address::SetAddress>("address"),
                                        });
}
Napi::Value Libtorrent::Address::GetAddress(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::address>::New(env, this->address);
}
void Libtorrent::Address::SetAddress(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::address *address = value.As<Napi::External<libtorrent::address>>().Data();
    this->address = address;
}
