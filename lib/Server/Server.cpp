#include "Server.h"
#include "../SocketManager/SocketManager.h"

/**
 * Initialize.
 *
 * @param port
 * @return void
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
 * @return void
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
 * @return void
 */
void Server::handle_connection(int socket_fd) {
    char buffer[256];
    while (recv(socket_fd, buffer, 255, 0) > 0) {
        receive_message(socket_fd, buffer);
        bzero(buffer, 256);
    }
    close(socket_fd);
}

/**
 * Send message.
 *
 * @param socket_fd
 * @param prompt
 * @return void
 */
void Server::send_message(int socket_fd, std::string prompt) {
    const char* prompt_char = prompt.c_str();
    send(socket_fd, (void *) prompt_char, strlen(prompt_char), MSG_NOSIGNAL);
    std::cout << "[Server::send_]" << prompt;
}

/**
 * Receive message.
 *
 * @param socket_fd
 * @param buffer
 * @return void
 */
void Server::receive_message(int socket_fd, char buffer[256]) {
    std::cout << buffer;
    send_message(socket_fd, "Ping ... \n");
}

/**
 * Authenticate.
 *
 * @param socket_fd
 * @return void
 */
void Server::authenticate(int socket_fd) {

}
