cmake_minimum_required(VERSION 3.15)
project(SServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SServer main.cpp Server.cpp Server.h SocketManager.cpp SocketManager.h)

SET(CMAKE_CXX_FLAGS -pthread)