#define _DEFAULT_SOURCE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


/**
 * Error
 *
 * @param message
 */
void error(const char *message)
{
    perror(message);
    exit(1);
}

/**
 * Open socket
 *
 * @return
 */
int open_socket()
{
    std::cout << "[1] Socket will be opened ... \n";

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (socket_fd < 0)
        error("Error opening socket_fd.");

    std::cout << "[2] Socket was opened ... \n";

    return socket_fd;
}

/**
 * Setup server address
 *
 * @param socket_fd
 * @param port
 * @return
 */
struct sockaddr_in setup_server_address(int &socket_fd, int port)
{
    std::cout << "[3] Server Address will be configured ... \n";

    struct sockaddr_in server_address;

    bzero((char *) &server_address, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    std::cout << "[4] Server Address was configured ... \n";

    return server_address;
}

/**
 * Set socket address as reusable
 * 
 * @param socket_fd 
 */
void mark_socket_address_as_reusable(int socket_fd)
{
    std::cout << "[5] Socket Address will be marked as reusable ... \n";

    int enable = 1;

    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        error("setsockopt(SO_REUSEADDR) failed");
    }

    std::cout << "[6] Socket Address was marked as reusable ... \n";
}

/**
 * Bind socket address
 * 
 * @param socket_fd 
 * @param server_address 
 */
void bind_socket_address(int socket_fd, struct sockaddr_in server_address)
{
    std::cout << "[7] Socket Address will be bound ... \n";

    if (bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error binding");
    }

    std::cout << "[8] Socket Address was bind ... \n";
}


int main(int argc, char *argv[]) {
    
    int new_socket_fd;
    socklen_t clientLen;
    char buffer[256];
    struct sockaddr_in cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    std::cout << "======================\n";
    std::cout << "= Server is starting =\n";
    std::cout << "======================\n";

    int socket_fd = open_socket();
    struct sockaddr_in server_address = setup_server_address(socket_fd,atoi(argv[1]));
    mark_socket_address_as_reusable(socket_fd);
    bind_socket_address(socket_fd, server_address);

    listen(socket_fd, 5);

    clientLen = sizeof(cli_addr);

    new_socket_fd = accept(socket_fd,
            (struct sockaddr *) &cli_addr, &clientLen);

    if (new_socket_fd < 0)
        error("Error on accept");

    printf("Server: Got new connection from %s port %d\n",
            inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    send(new_socket_fd, "Hello, world\n", 13, 0);

    bzero(buffer, 256);

    n = read(new_socket_fd, buffer, 255);

    if (n < 0) error("Error reading data from socket_fd");
    printf("Here is the message: %s\n", buffer);

    close(new_socket_fd);
    close(socket_fd);


    return 0;
}
