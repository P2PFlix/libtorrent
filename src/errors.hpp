#ifndef ERRORS_H
#define ERRORS_H

#include <vector>
#include <string>
#include <napi.h>

namespace LibtorrentNode
{
    const std::string INCORRECT_AGUMENTS_SUPPLIED = "Incorrect arguments supplied";

    const std::vector<std::string> ERRORS = {
        "Expected usage is 'addTorrent(file_path: string, magnet_uri: string)'",
        "Expected usage is 'getTorrent(id: nunmber)'",
        "Expected usage is 'setLimit(limit: number, type: string)'",
        "Error while pausing torrent",
        "Error while resuming torrent",
        "Error while getting torrent files",
        "Expected usage is 'removeTorrent(id: number)'",
    };

    /**
     * @brief A helper function to throw n-api error messages
     * Eg. throwAsJavaScriptException(env, { INCORRECT_ARGUMENTS_SUPPLIED, ERRORS[1], exception.what() })
     *
     * @param env
     * @param parts Initializer list for std::vector< std::string > &
     */
    const void throwAsJavaScriptException(Napi::Env env, const std::vector<std::string> &parts);
} // namespace LibtorentNode

#endif
