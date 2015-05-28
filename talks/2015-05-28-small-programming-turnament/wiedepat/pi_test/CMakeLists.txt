cmake_minimum_required(VERSION 2.8.12)
project(pi)

#cpp 11
set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(pitest pitest.cpp) 
target_link_libraries(pitest ${Boost_LIBRARIES})
