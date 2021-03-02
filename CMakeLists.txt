cmake_minimum_required(VERSION 3.15)
project(SocketServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SocketServer main.cpp lib/Server.cpp lib/Server.h lib/SocketManager.cpp lib/SocketManager.h)

SET(CMAKE_CXX_FLAGS -pthread)