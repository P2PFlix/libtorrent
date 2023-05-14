cmake_minimum_required(VERSION 3.12.0)
set (CMAKE_CXX_STANDARD 17)
project(libtorrentNode)
file(GLOB SOURCE_FILES "src/*.hpp" "src/*.cpp")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
add_definitions(-DNAPI_CPP_EXCEPTIONS)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REGEX REPLACE "[\r\n\"]" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC} ${NODE_ADDON_API_DIR})
target_link_libraries(${PROJECT_NAME} torrent-rasterbar)
add_subdirectory(lib/libtorrent)
