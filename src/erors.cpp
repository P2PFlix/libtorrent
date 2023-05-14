#include "errors.hpp"

const std::string LibtorrentNode::buildErrorMessage(const std::vector<std::string> &parts)
{
    std::string retVal = "";
    for (auto i : parts)
    {
        retVal.append("\n");
        retVal.append(i);
    }

    return retVal;
}