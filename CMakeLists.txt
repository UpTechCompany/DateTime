cmake_minimum_required(VERSION 3.25)
project(DateTime)

set(CMAKE_CXX_STANDARD 23)

add_executable(DateTime main.cpp DateTime/DateTime.h DateTime/DateTime.cpp)
