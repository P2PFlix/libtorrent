#ifndef MAIN_H
#define MAIN_H

#include "bindings.hpp"
#include "version.hpp"
#include "errors.hpp"

/**
 * @brief Main function to init the N-API module and call each class' Init function to register
 * them and their contents with the Node.JS runtime
 *
 * @param env
 * @param exports
 * @return Napi::Object
 */
Napi::Object InitAll(Napi::Env env, Napi::Object exports);

#endif