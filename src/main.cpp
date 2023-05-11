#include <node.h>
#include "torrent.cpp"

LibtorrentNodeRandom r;

void Method(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "world").ToLocalChecked());
}

void Shuffle(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "").ToLocalChecked());
	r.shuffle();
}

void Initialize(v8::Local<v8::Object> exports)
{
	NODE_SET_METHOD(exports, "hello", Method);
	NODE_SET_METHOD(exports, "shuffle", Shuffle);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
