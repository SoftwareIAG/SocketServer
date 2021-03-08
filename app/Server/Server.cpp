#include "Server.h"
#include "../../lib/SocketManager/SocketManager.h"
#include "mysql_driver.h"
#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/statement.h"
#include <cppconn/prepared_statement.h>
#include "../../main.h"
#include <uuid/uuid.h>

/**
 * Initialize.
 *
 * @param port
 * @return void
 */
void Server::initialize(int port) {
    int socket_fd = SocketManager::open_socket();
    struct sockaddr_in server_address = SocketManager::setup_server_address(socket_fd, port);
    SocketManager::mark_socket_address_as_reusable(socket_fd);
    SocketManager::bind_socket_address(socket_fd, server_address);
    start_listening(socket_fd);
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
/**
 * Start listening.
 *
 * @param socket
 * @return void
 */
void Server::start_listening(int socket) {
    while(true) {
        int new_socket_fd = -1;
        struct sockaddr_in client_address{};
        socklen_t client_len = sizeof(client_address);
        listen(socket, 5);
        new_socket_fd = accept(socket, (struct sockaddr *) &client_address, &client_len);
        if (new_socket_fd < 0) perror("Error: failed to connect to incoming connection ... \n");
        clientList[new_socket_fd] = client_address;
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::PreparedStatement *pstmt;
        std::string INSERT_SOCKET_INTO_SOCKETS_TABLE = "INSERT INTO sockets(ip, port, uuid) VALUES (?, ?, ?)";
        driver = get_driver_instance();
        con = driver->connect(configManager->get("DB_URL"), configManager->get("DB_USERNAME"), configManager->get("DB_PASSWORD"));
        con->setSchema(configManager->get("DB_NAME"));
        pstmt = con->prepareStatement(INSERT_SOCKET_INTO_SOCKETS_TABLE);
        uuid_t id;
        uuid_generate(id);
        char *uuid = new char[100];
        uuid_unparse(id, uuid);
        pstmt->setString(1, inet_ntoa(client_address.sin_addr));
        pstmt->setInt(2, htons(client_address.sin_port));
        pstmt->setString(3, uuid);
        pstmt->executeUpdate();
        delete pstmt;
        delete con;
        printf("Server: Got new connection from %s port %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        std::thread child_thread (&Server::handle_connection, this, new_socket_fd, client_address, uuid);
        child_thread.detach();
    }
}
#pragma clang diagnostic pop

/**
 * Handle connection.
 *
 * @param socket_fd
 * @return void
 */
void Server::handle_connection(int socket_fd, sockaddr_in client_address, char* uuid) {
    char buffer[256];
    while (recv(socket_fd, buffer, 255, 0) > 0) {
        receive_message(socket_fd, buffer);
        bzero(buffer, 256);
    }
    close(socket_fd);
    clientList.erase(socket_fd);
    sql::Driver *driver;
    sql::Connection *con;
    sql::PreparedStatement *pstmt;
    std::string UPDATE_SOCKET_IN_SOCKETS_TABLE = "UPDATE sockets SET connected = false, disconnected_at = now() WHERE uuid = ?";
    driver = get_driver_instance();
    con = driver->connect(configManager->get("DB_URL"), configManager->get("DB_USERNAME"), configManager->get("DB_PASSWORD"));
    con->setSchema(configManager->get("DB_NAME"));
    pstmt = con->prepareStatement(UPDATE_SOCKET_IN_SOCKETS_TABLE);
    pstmt->setString(1, uuid);
    pstmt->executeUpdate();
    delete pstmt;
    delete con;
}

/**
 * Send message.
 *
 * @param socket_fd
 * @param prompt
 * @return void
 */
void Server::send_message(int socket_fd, const std::string& prompt) {
    const char *prompt_char;
    prompt_char = prompt.c_str();
    send(socket_fd, (void *) prompt_char, strlen(prompt_char), MSG_NOSIGNAL);
    std::cout << "[Server::send]" << prompt;
}

/**
 * Receive message.
 *
 * @param socket_fd
 * @param buffer
 * @return void
 */
void Server::receive_message(int socket_fd, char buffer[256]) {
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
