cmake_minimum_required(VERSION 3.15)
project(Heuristic)

set(CMAKE_CXX_STANDARD 17)

add_executable(Heuristic main.cpp A_search.cpp A_search.h Open.cpp Open.h Node.cpp Node.h Map.cpp Map.h Closed.cpp Closed.h Path.cpp Path.h)