cmake_minimum_required(VERSION 3.12.0)
set(CMAKE_CXX_STANDARD 17)
set(deprecated-functions OFF)
set(FETCHCONTENT_QUIET FALSE) # Needed to print downloading progress
set(webtorrent ON)
project(libtorrent)

include(FetchContent)
message("Fetching external lib")
message(${CMAKE_SOURCE_DIR}/lib/openssl)


FetchContent_Declare(
    openssl
    GIT_REPOSITORY https://github.com/janbar/openssl-cmake.git
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/lib/openssl
    GIT_TAG 392d455cd0b0fe992b312c9648eb5ea87e3afcea
)

FetchContent_MakeAvailable(openssl)
set(OPENSSL_ROOT_DIR ${CMAKE_SOURCE_DIR}/lib/openssl/*)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(OPENSSL_CRYPTO_LIBRARY ${CMAKE_SOURCE_DIR}/build/_deps/openssl-build/crypto/Debug)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(OPENSSL_CRYPTO_LIBRARY ${CMAKE_SOURCE_DIR}/build/_deps/openssl-build/crypto/Release)
endif()

# FetchContent_Declare(
#   Boost
#   GIT_REPOSITORY https://github.com/boostorg/boost.git
#   SOURCE_DIR ${CMAKE_SOURCE_DIR}/lib/boost
#   GIT_TAG boost-1.80.0
# )
# FetchContent_MakeAvailable(Boost)

# Download and Extract the Boost Library from GitHub
# message(STATUS "Downloading and extracting Boost Library Sources. This will take some time...")
# include(FetchContent)
# FetchContent_Declare(
#     Boost
#     URL https://github.com/boostorg/boost/releases/download/boost-1.81.0/boost-1.81.0.7z # downloading a zip release speeds up the download
#     USES_TERMINAL_DOWNLOAD TRUE 
#     GIT_PROGRESS TRUE   
#     DOWNLOAD_NO_EXTRACT FALSE
# )
# FetchContent_MakeAvailable(Boost)

# message("fetching boost--DONE")

# set(Boost_INCLUDE_DIR "boost_dir" CACHE)
# set(Boost_NO_BOOST_CMAKE on CACHE BOOL)
# set(DBoost_NO_SYSTEM_PATHS on CACHE BOOL)
# set(BOOST_INCLUDE_LIBRARIES thread filesystem system)
# set(BOOST_ENABLE_CMAKE on)
# set( BOOST_ROOT "" CACHE PATH "Boost library path" )
# set( Boost_NO_SYSTEM_PATHS on CACHE BOOL "Do not search system for Boost" )

FetchContent_Declare(
    libtorrent
    GIT_REPOSITORY https://github.com/arvidn/libtorrent.git
    SOURCE_DIR  ${CMAKE_SOURCE_DIR}/lib/libtorrent
    GIT_TAG b82b350b38147ac7ddf6ec41027ebe07dc15f913
    USES_TERMINAL_DOWNLOAD TRUE
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(libtorrent)

FetchContent_GetProperties(libtorrent)
if(NOT libtorrent_POPULATED)
  FetchContent_Populate(libtorrent)
endif()




# add_subdirectory(${CMAKE_SOURCE_DIR}/lib/libtorrent)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX .node)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC} ${CMAKE_JS_INC}/../node-addon-api node_modules/node-addon-api include)
target_link_libraries(${PROJECT_NAME} torrent-rasterbar ${CMAKE_JS_LIB})
# add_subdirectory(lib/libtorrent)