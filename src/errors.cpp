#include "errors.hpp"

const void LibtorrentNode::throwAsJavaScriptException(Napi::Env env, const std::vector<std::string> &parts)
{
    std::string retVal = "Error:";

    for (auto i : parts)
    {
        retVal.append("\n");
        retVal.append(i);
    }

    Napi::TypeError::New(env, retVal).ThrowAsJavaScriptException();
}
