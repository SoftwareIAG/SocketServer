#define _DEFAULT_SOURCE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void error(const char *message)
{
    perror(message);
    exit(1);
}



int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;

    int socketFileDescriptor, newSocketFileDescriptor, portNumber;
    socklen_t clientLen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor < 0)
        error("Error openning socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));

    portNumber = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portNumber);

    if (bind(socketFileDescriptor, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0)
            error("Error binding");

    listen(socketFileDescriptor, 5);

    clientLen = sizeof(cli_addr);

    newSocketFileDescriptor = accept(socketFileDescriptor,
            (struct sockaddr *) &cli_addr, &clientLen);

    if (newSocketFileDescriptor < 0)
        error("Error on accept");

    printf("Server: Got new connection from %s port %d\n",
            inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    send(newSocketFileDescriptor, "Hello, world\n", 13, 0);

    bzero(buffer, 256);

    n = read(newSocketFileDescriptor, buffer, 255);

    if (n < 0) error("Error reading data from socket");
    printf("Here is the message: %s\n", buffer);

    close(newSocketFileDescriptor);
    close(socketFileDescriptor);


    return 0;
}
