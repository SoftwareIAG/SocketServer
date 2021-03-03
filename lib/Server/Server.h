#ifndef SOCKET_SERVER_SERVER_H
#define SOCKET_SERVER_SERVER_H

#pragma once

#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <thread>
#include <map>

class Server {
private:
    virtual void handle_connection(int socket_fd);
public:
    Server() = default;
    void initialize(int port);
    void start_listening(int socket);
    void authenticate(int socket_fd);
    static void send_message(int socket_fd, const std::string& prompt);
    static void receive_message(int socket_fd, char buffer[256]);
    ~Server() = default;
};

#endif //SOCKET_SERVER_SERVER_H
