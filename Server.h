#ifndef SSERVER_SERVER_H
#define SSERVER_SERVER_H

#pragma once

#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
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
    void sendMessage(int socket_fd, std::string prompt);
    ~Server() = default;
};
#endif //SSERVER_SERVER_H
