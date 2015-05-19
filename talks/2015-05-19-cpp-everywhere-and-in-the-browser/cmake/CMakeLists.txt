cmake_minimum_required(VERSION 2.8.8)
project (lib-alarm-renderer)

add_definitions(-std=c++11)

set(CMAKE_BUILD_TYPE "DEBUG")

include_directories(BEFORE ${CMAKE_CURRENT_LIST_DIR}/src)
file (GLOB_RECURSE SRC_FILES src/*.cpp)

if (DEFINED EMSCRIPTEN)
  add_library(alarm-renderer SHARED ${SRC_FILES})
else (DEFINED EMSCRIPTEN)
  add_executable(alarm-renderer ${SRC_FILES})
endif(DEFINED EMSCRIPTEN)

target_link_libraries(alarm-renderer SDL SDL_gfx SDL_ttf)

file (COPY ${CMAKE_CURRENT_LIST_DIR}/Arial DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if (DEFINED EMSCRIPTEN)
  set_target_properties(alarm-renderer 
    PROPERTIES SUFFIX ".js"
               LINK_FLAGS " --bind ")
  em_link_js_library(alarm-renderer ${libraryJsFiles})
  # add -O2 to minify
endif (DEFINED EMSCRIPTEN)

