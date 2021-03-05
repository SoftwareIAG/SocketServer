#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "main.h"
#include "lib/Server/Server.h"
#include "lib/LinkList/LinkList.h"
#include "lib/HashTable/HashTable.h"
#include "lib/ConfigManager/ConfigManager.h"

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

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    Server server;
    server.initialize(atoi(configManager->get("PORT")));
}
