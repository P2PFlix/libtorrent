#include <node.h>
#include "torrent.cpp"

#include <libtorrent/bitfield.hpp>

void Method(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "world").ToLocalChecked());
}

void Shuffle(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	libtorrent::bitfield test1(100100, false);
	std::string s = "no. of 1s: |" + std::to_string(test1.count()) + "|\n" + "no. of 1s: |" + std::to_string(test1.size() - test1.count()) + "|";
	args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, s.c_str()).ToLocalChecked());
}

void Initialize(v8::Local<v8::Object> exports)
{
	NODE_SET_METHOD(exports, "hello", Method);
	NODE_SET_METHOD(exports, "shuffle", Shuffle);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
