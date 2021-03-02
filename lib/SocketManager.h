#ifndef SOCKET_SERVER_SOCKETMANAGER_H
#define SOCKET_SERVER_SOCKETMANAGER_H

#include <netinet/in.h>
#include <iostream>
#include <strings.h>
#include "Server.h"

class SocketManager {
public:
    int open_socket();
    struct sockaddr_in setup_server_address(int &socket_fd, int port);
    void mark_socket_address_as_reusable(int socket_fd);
    void bind_socket_address(int socket_fd, struct sockaddr_in server_address);
};
#endif //SOCKET_SERVER_SOCKETMANAGER_H
