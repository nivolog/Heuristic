cmake_minimum_required(VERSION 3.15)
project(Heuristic)

set(CMAKE_CXX_STANDARD 17)

add_executable(Heuristic main.cpp A_search.cpp A_search.h OPEN.cpp OPEN.h NODE.cpp NODE.h MAP.cpp MAP.h CLOSED.cpp CLOSED.h PATH.cpp PATH.h)