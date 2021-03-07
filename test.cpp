#include <cassert>
#include "main.h"
#include <netinet/in.h>
#include "lib/LinkList/LinkList.h"
#include "lib/HashTable/HashTable.h"
#include "lib/SocketManager/SocketManager.h"
#include "lib/ConfigManager/ConfigManager.h"
#include "gtest/gtest.h"

TEST(LinkListTest, InsertingAndFetchingValues) {
    LinkList linkList;
    linkList.insert(10);
    linkList.insert(20);
    linkList.insert(30);
    linkList.render();
    EXPECT_EQ(linkList.search(10), 1);
    linkList.remove(10);
    EXPECT_EQ(linkList.search(10), 0);
    assert(linkList.search(10) == 0);
    EXPECT_EQ(linkList.search(20), 1);
    EXPECT_EQ(linkList.search(30), 1);
}

TEST(SocketManagerTest, ExecutingCode) {
    int socket_fd = SocketManager::open_socket();
    EXPECT_NE(socket_fd, -1);
    sockaddr_in socket_address = SocketManager::setup_server_address(socket_fd, 9991);
    EXPECT_EQ(socket_address.sin_family, AF_INET);
    EXPECT_EQ(socket_address.sin_addr.s_addr, INADDR_ANY);
    EXPECT_EQ(socket_address.sin_port, htons(9991));
    SocketManager::mark_socket_address_as_reusable(socket_fd);
    SocketManager::bind_socket_address(socket_fd, socket_address);
}

TEST(ConfigManagerTest, FetchingValues) {
    configManager->initialize();
    EXPECT_EQ(configManager->get("ENV"), "LOCAL");
    EXPECT_EQ(configManager->values["ENV"], "LOCAL");
}

TEST(HashTableTest, InsertingValues) {
    HashTable hashTable;
    std::string identifier = "ABC";
    std::string value = "DEF";
    hashTable.insert(identifier, value);
    hashTable.render();
    EXPECT_EQ(hashTable.get(identifier), "DEF");
    EXPECT_EQ(hashTable.exists(identifier), 1);
    EXPECT_EQ(hashTable.exists(identifier), 1);
    hashTable.remove(identifier);
    EXPECT_EQ(hashTable.exists(identifier), 0);
}

/**
 * Test.
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
