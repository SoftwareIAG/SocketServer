#ifndef SOCKET_SERVER_SOCKET_MANAGER_H
#define SOCKET_SERVER_SOCKET_MANAGER_H

#include <netinet/in.h>
#include <iostream>
#include <strings.h>
#include "../Server/Server.h"

class SocketManager {
public:
    static int open_socket();
    static struct sockaddr_in setup_server_address(int &socket_fd, int port);
    static void mark_socket_address_as_reusable(int socket_fd);
    static void bind_socket_address(int socket_fd, struct sockaddr_in server_address);
};

#endif //SOCKET_SERVER_SOCKET_MANAGER_H
