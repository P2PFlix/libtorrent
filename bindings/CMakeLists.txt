cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)

project(libtorrentNode)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

if(MSVC)
    if(MSVC_VERSION GREATER_EQUAL "1900")
        include(CheckCXXCompilerFlag)
        CHECK_CXX_COMPILER_FLAG("/std:c++14" _cpp_14_flag_supported)

        if(_cpp_14_flag_supported)
            add_compile_options("/std:c++14")
        endif(_cpp_14_flag_supported)
    endif(MSVC_VERSION GREATER_EQUAL "1900")

    add_compile_definitions(WIN32_LEAN_AND_MEAN)
endif(MSVC)

add_subdirectory(torrent)