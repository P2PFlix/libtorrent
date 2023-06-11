file(GLOB TEST_SOURCE_FILES "*.cpp")

add_executable(test ${TEST_SOURCE_FILES})
target_include_directories(test PRIVATE ${CMAKE_JS_INC} node_modules/node-addon-api)

target_link_libraries(test torrent-rasterbar)