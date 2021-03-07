cmake_minimum_required(VERSION 3.15)
project(SocketServer)

set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(SocketServer
        main.cpp
        app/Server/Server.cpp
        app/Server/Server.h
        lib/SocketManager/SocketManager.cpp
        lib/SocketManager/SocketManager.h
        lib/ConfigManager/ConfigManager.cpp
        lib/ConfigManager/ConfigManager.h
        lib/HashTable/HashTable.cpp
        lib/HashTable/HashTable.h
        lib/LinkList/LinkList.cpp
        lib/LinkList/LinkList.h main.h
)

add_executable(RunTests
        test.cpp
        app/Server/Server.cpp
        app/Server/Server.h
        lib/SocketManager/SocketManager.cpp
        lib/SocketManager/SocketManager.h
        lib/ConfigManager/ConfigManager.cpp
        lib/ConfigManager/ConfigManager.h
        lib/HashTable/HashTable.cpp
        lib/HashTable/HashTable.h
        lib/LinkList/LinkList.cpp
        lib/LinkList/LinkList.h main.h
)

add_executable(ExecuteCommand
        run-command.cpp
        app/Server/Server.cpp
        app/Server/Server.h
        lib/SocketManager/SocketManager.cpp
        lib/SocketManager/SocketManager.h
        lib/ConfigManager/ConfigManager.cpp
        lib/ConfigManager/ConfigManager.h
        lib/HashTable/HashTable.cpp
        lib/HashTable/HashTable.h
        lib/LinkList/LinkList.cpp
        lib/LinkList/LinkList.h main.h
        app/RunCommand/RunCommand.cpp app/RunCommand/RunCommand.h)

target_link_libraries(ExecuteCommand mysqlcppconn)
target_link_libraries(RunTests ${GTEST_LIBRARIES} pthread)
SET(CMAKE_CXX_FLAGS "-pthread --coverage")
