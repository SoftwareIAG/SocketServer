#include "SocketManager.h"
#define TRUE   1

/**
 * Open socket.
 *
 * @return int
 */
int SocketManager::open_socket() {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) perror("Error: opening socket file descriptor ... \n");
    return socket_fd;
}

/**
 * Setup server address.
 *
 * @param socket_fd
 * @param port
 * @return sockaddr_in
 */
sockaddr_in SocketManager::setup_server_address(int &socket_fd, int port) {
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);
    return server_address;
}

/**
 * Mark socket address as reusable.
 *
 * @param socket_fd
 * @return void
 */
void SocketManager::mark_socket_address_as_reusable(int socket_fd) {
    std::cout << "[SocketManager::mark_socket_address_as_reusable] Socket Address will be marked as reusable ... " << std::endl;
    int enable = TRUE;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) perror("Error: reusing socket address ... \n");
    std::cout << "[SocketManager::mark_socket_address_as_reusable] Socket Address was marked as reusable ... " << std::endl;
}

/**
 * Bind socket address.
 *
 * @param socket_fd
 * @param server_address
 * @return void
 */
void SocketManager::bind_socket_address(int socket_fd, sockaddr_in server_address) {
    std::cout << "[SocketManager::bind_socket_address] Socket Address will be bound ... " << std::endl;
    if (bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) perror("Error: binding socket address ... \n");
    std::cout << "[SocketManager::bind_socket_address] Socket Address was bound ... " << std::endl;
}
