#include "SocketManager.h"
#define TRUE   1

/**
 * Open socket.
 *
 * @return
 */
int SocketManager::open_socket() {
    std::cout << "[SocketManager::open_socket] Socket will be opened ... \n";
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
        perror("Error: opening socket file descriptor ... \n");
    std::cout << "[SocketManager::open_socket] Socket was opened ... \n";
    return socket_fd;
}

/**
 * Setup server address.
 *
 * @param socket_fd
 * @param port
 * @return
 */
sockaddr_in SocketManager::setup_server_address(int &socket_fd, int port) {
    std::cout << "[SocketManager::setup_server_address] Server Address will be setup ... \n";
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);
    std::cout << "[SocketManager::setup_server_address] Server Address was setup ... \n";
    return server_address;
}

/**
 * Mark socket address as reusable.
 *
 * @param socket_fd
 */
void SocketManager::mark_socket_address_as_reusable(int socket_fd) {
    std::cout << "[SocketManager::mark_socket_address_as_reusable] Socket Address will be marked as reusable ... \n";
    int enable = TRUE;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        perror("Error: reusing socket address ... \n");
    std::cout << "[SocketManager::mark_socket_address_as_reusable] Socket Address was marked as reusable ... \n";
}

/**
 * Bind socket address.
 *
 * @param socket_fd
 * @param server_address
 */
void SocketManager::bind_socket_address(int socket_fd, sockaddr_in server_address) {
    std::cout << "[SocketManager::bind_socket_address] Socket Address will be bound ... \n";
    if (bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
        perror("Error: binding socket address ... \n");
    std::cout << "[SocketManager::bind_socket_address] Socket Address was bound ... \n";
}