cmake_minimum_required(VERSION 3.5)
project(NagyHF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Source.cpp DirectedGraph.cpp DirectedGraph.h BFS.cpp BFS.h DFS.cpp DFS.h CC.cpp CC.h Graph.cpp Graph.h NonrecursiveDFS.cpp NonrecursiveDFS.h)
add_executable(NagyHF ${SOURCE_FILES})
