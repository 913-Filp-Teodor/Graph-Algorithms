cmake_minimum_required(VERSION 3.17)
project(A1)

set(CMAKE_CXX_STANDARD 14)

add_executable(A1 main.cpp DirectedGraph.cpp DirectedGraph.h GraphUtils.cpp GraphUtils.h WDirectedGraph.h WDirectedGraph.cpp)