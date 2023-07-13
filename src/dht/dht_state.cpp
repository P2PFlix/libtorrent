#include "main.hpp"
Libtorrent::Dht::DhtState::DhtState(const Napi::CallbackInfo &info) : Napi::ObjectWrap<DhtState>(info)
{
    if (info.Length() < 1)
    {
        this->dht_state = new libtorrent::dht::dht_state();
    }
    else
    {
        Napi::Object dht_state_arg = info[0].As<Napi::Object>();
        libtorrent::dht::dht_state *dht_state = dht_state_arg.Get("dhtState").As<Napi::External<libtorrent::dht::dht_state>>().Data();
        this->dht_state = new libtorrent::dht::dht_state(*dht_state);
    }
}
Napi::Function Libtorrent::Dht::DhtState::Init(Napi::Env env)
{
    return DefineClass(env, "DhtState", {
                                            InstanceAccessor<&DhtState::GetDhtState, &DhtState::SetDhtState>("dhtState"),
                                            InstanceAccessor<&DhtState::GetNodes, &DhtState::SetNodes>("nodes"),
                                        });
}
Napi::Value Libtorrent::Dht::DhtState::GetDhtState(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::dht::dht_state>::New(env, this->dht_state);
}
void Libtorrent::Dht::DhtState::SetDhtState(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::dht::dht_state *dht_state = value.As<Napi::External<libtorrent::dht::dht_state>>().Data();
    this->dht_state = dht_state;
}
Napi::Value Libtorrent::Dht::DhtState::GetNodes(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::Array nodes_arg = Napi::Array::New(env);
    std::vector<libtorrent::udp::endpoint> nodes = this->dht_state->nodes;
    for (libtorrent::udp::endpoint node : nodes)
    {
        Napi::Object node_arg = Udp::Endpoint::Init(env).New({});
        node_arg.Set("endpoint", Napi::External<libtorrent::udp::endpoint>::New(env, new libtorrent::udp::endpoint(node)));
        nodes_arg.Set(nodes_arg.Length(), node_arg);
    }
    return nodes_arg;
}
void Libtorrent::Dht::DhtState::SetNodes(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    Napi::Array nodes_arg = value.As<Napi::Array>();
    std::vector<libtorrent::udp::endpoint> nodes = std::vector<libtorrent::udp::endpoint>();
    for (int i = 0; i < nodes_arg.Length(); i += 1)
    {
        libtorrent::udp::endpoint *node = nodes_arg.Get(i)
                                              .As<Napi::Object>()
                                              .Get("endpoint")
                                              .As<Napi::External<libtorrent::udp::endpoint>>()
                                              .Data();
        nodes.push_back(*node);
    }
    this->dht_state->nodes = nodes;
}
