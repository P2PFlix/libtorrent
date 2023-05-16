#include "errors.hpp"

const void LibtorrentNode::throwAsJavaScriptException(Napi::Env env, const std::vector<std::string> &parts)
{
    std::string retVal = boost::algorithm::join(parts, "\n");

    Napi::TypeError::New(env, retVal).ThrowAsJavaScriptException();
}
