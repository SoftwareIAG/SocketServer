#include <cassert>
#include "main.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include "lib/LinkList/LinkList.h"
#include "lib/HashTable/HashTable.h"
#include "lib/SocketManager/SocketManager.h"
#include "lib/ConfigManager/ConfigManager.h"
#include "lib/Server/Server.h"

/**
 * Test.
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[]) {

    std::cout << "=======================" << std::endl;
    std::cout << "= ConfigManager Tests =" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "                       " << std::endl;

    configManager->initialize();
    assert(configManager->get("ENV") == "LOCAL");
    std::cout << "configManager->get('ENV') returns 'LOCAL' as expected." << std::endl;
    assert(configManager->values["ENV"] == "LOCAL");
    std::cout << "configManager->values['ENV'] returns 'LOCAL' as expected." << std::endl;

    std::cout << "                   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "= HashTable Tests =" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "                   " << std::endl;

    HashTable hashTable;
    std::string identifier = "ABC";
    std::string value = "DEF";
    hashTable.insert(identifier, value);
    std::cout << "hashTable.insert('ABC', 'DEF') executed." << std::endl;
    hashTable.render();
    std::cout << "hashTable.render() executed." << std::endl;

    assert(hashTable.get(identifier) == value);
    std::cout << "hashTable.get('ABC') returns 'DEF' as expected." << std::endl;
    assert(hashTable.exists(identifier) == 1);
    std::cout << "hashTable.exists('ABC') returns 'true' as expected." << std::endl;
    hashTable.remove(identifier);
    std::cout << "hashTable.remove('ABC') executed." << std::endl;
    assert(hashTable.exists(identifier) == 0);
    std::cout << "hashTable.exists('ABC') returns 'false' as expected." << std::endl;

    std::cout << "                  " << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "= LinkList Tests =" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "                  " << std::endl;

    LinkList linkList;
    linkList.insert(10);
    std::cout << "linkList.insert(10) executed." << std::endl;
    linkList.insert(20);
    std::cout << "linkList.insert(20) executed." << std::endl;
    linkList.insert(30);
    std::cout << "linkList.insert(30) executed." << std::endl;
    linkList.render();
    std::cout << "linkList.render() executed." << std::endl;
    assert(linkList.search(10) == 1);
    std::cout << "linkList.search(10) returns 'true' as expected." << std::endl;
    linkList.remove(10);
    std::cout << "linkList.remove(10) executed." << std::endl;
    assert(linkList.search(10) == 0);
    std::cout << "linkList.search(10) returns 'false' as expected." << std::endl;
    assert(linkList.search(20) == 1);
    std::cout << "linkList.search(20) returns 'true' as expected." << std::endl;
    assert(linkList.search(30) == 1);
    std::cout << "linkList.search(30) returns 'true' as expected." << std::endl;

    std::cout << "                       " << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "= SocketManager Tests =" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "                       " << std::endl;

    int socket_fd = SocketManager::open_socket();
    assert(socket_fd != -1);
    std::cout << "SocketManager::open_socket() returns integer with no error (-1)." << std::endl;
    sockaddr_in socket_address = SocketManager::setup_server_address(socket_fd, 9991);
    assert(socket_address.sin_family == AF_INET);
    std::cout << "SocketManager::setup_server_address(socket_fd, 9991) returns sockaddr_in with sin_family property as AF_INET." << std::endl;
    assert(socket_address.sin_addr.s_addr == INADDR_ANY);
    std::cout << "SocketManager::setup_server_address(socket_fd, 9991) returns sockaddr_in with sin_addr property with s_addr property as INADDR_ANY." << std::endl;
    assert(socket_address.sin_port == htons(9991));
    std::cout << "SocketManager::setup_server_address(socket_fd, 9991) returns sockaddr_in with sin_port property as htons(9991)." << std::endl;

    SocketManager::mark_socket_address_as_reusable(socket_fd);
    std::cout << "SocketManager::mark_socket_address_as_reusable(socket_fd) mark the socket_fd as reusable." << std::endl;

    SocketManager::bind_socket_address(socket_fd, socket_address);
    std::cout << "SocketManager::bind_socket_address(socket_fd, socket_address) binds the socket to an address." << std::endl;

}
