cmake_minimum_required(VERSION 3.15)
project(SocketServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SocketServer main.cpp lib/Server/Server.cpp lib/Server/Server.h lib/SocketManager/SocketManager.cpp lib/SocketManager/SocketManager.h lib/ConfigManager/ConfigManager.cpp lib/ConfigManager/ConfigManager.h lib/HashTable/HashTable.cpp lib/HashTable/HashTable.h lib/LinkList/LinkList.cpp lib/LinkList/LinkList.h lib/HashNode/HashNode.cpp lib/HashNode/HashNode.h)

SET(CMAKE_CXX_FLAGS -pthread)