#include "main.hpp"
Libtorrent::IovecT::IovecT(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IovecT>(info)
{
    if (info.Length() < 1)
    {
        this->iovec_t = new libtorrent::iovec_t();
    }
    else
    {
        Napi::Object iovec_t_arg = info[0].As<Napi::Object>();
        libtorrent::iovec_t *iovec_t = iovec_t_arg.Get("iovecT").As<Napi::External<libtorrent::iovec_t>>().Data();
        this->iovec_t = new libtorrent::iovec_t(*iovec_t);
    }
}
Napi::Function Libtorrent::IovecT::Init(Napi::Env env)
{
    return DefineClass(env, "IovecT", {
                                          InstanceAccessor<&IovecT::GetIovecT, &IovecT::SetIovecT>("iovecT"),
                                          InstanceMethod<&IovecT::Data>("data"),
                                      });
}
Napi::Value Libtorrent::IovecT::GetIovecT(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::iovec_t>::New(env, this->iovec_t);
}
void Libtorrent::IovecT::SetIovecT(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::iovec_t *iovec_t = value.As<Napi::External<libtorrent::iovec_t>>().Data();
    this->iovec_t = iovec_t;
}
Napi::Value Libtorrent::IovecT::Data(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Buffer<char>::New(env, this->iovec_t->data(), this->iovec_t->size());
}
