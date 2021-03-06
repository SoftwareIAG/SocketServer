#include <iostream>
#include "main.h"
#include "app/Server/Server.h"
#include "lib/LinkList/LinkList.h"
#include "lib/HashTable/HashTable.h"
#include "lib/ConfigManager/ConfigManager.h"
#include "mysql_driver.h"
#include "mysql_connection.h"

/**
 * Main.
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[]) {
    std::cout << "=========================" << std::endl;
    std::cout << "= Server is configuring =" << std::endl;
    std::cout << "=========================" << std::endl;

    configManager->initialize();

    std::cout << "======================" << std::endl;
    std::cout << "= Server is starting =" << std::endl;
    std::cout << "======================" << std::endl;

    Server server;
    server.initialize(stoi(configManager->get("PORT")));
}
