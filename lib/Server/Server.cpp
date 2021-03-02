#include "Server.h"
#include "../SocketManager/SocketManager.h"

/**
 * Initialize.
 *
 * @param port
 */
void Server::initialize(int port)
{
    SocketManager socketManager;
    int socket_fd = socketManager.open_socket();
    struct sockaddr_in server_address = socketManager.setup_server_address(socket_fd, port);
    socketManager.mark_socket_address_as_reusable(socket_fd);
    socketManager.bind_socket_address(socket_fd, server_address);
    start_listening(socket_fd);
}

/**
 * Start listening.
 *
 * @param socket
 */
void Server::start_listening(int socket) {
    while(1) {
        int new_socket_fd = -1;
        struct sockaddr_in client_address;
        socklen_t client_len = sizeof(client_address);
        listen(socket, 5);
        new_socket_fd = accept(socket, (struct sockaddr *) &client_address, &client_len);
        if (new_socket_fd < 0)
            perror("Error: failed to connect to incoming connection ... \n");
        printf("Server: Got new connection from %s port %d\n",
               inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        std::thread child_thread (&Server::handle_connection, this, new_socket_fd);
        child_thread.detach();
    }
}

/**
 * Handle connection.
 *
 * @param socket_fd
 */
void Server::handle_connection(int socket_fd) {
    char buffer[256];
    std::string response = "Ping ... \n";
    const char* response_char = response.c_str();
    while (recv(socket_fd, buffer, 255, 0) > 0) {
        std::cout << buffer;
        send(socket_fd, (void *) response_char, strlen(response_char), MSG_NOSIGNAL);
        std::cout << response;
        bzero(buffer, 256);
    }
    close(socket_fd);
}

/**
 * Send message.
 *
 * @param socket_fd
 * @param prompt
 */
void Server::sendMessage(int socket_fd, std::string prompt) {

}

/**
 * Authenticate.
 *
 * @param socket_fd
 */
void Server::authenticate(int socket_fd) {

}
