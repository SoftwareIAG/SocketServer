#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "lib/Server/Server.h"
#include "lib/LinkList/LinkList.h"
#include "lib/HashTable/HashTable.h"

/**
 * Main.
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[]) {
    std::cout << "======================\n";
    std::cout << "= Server is starting =\n";
    std::cout << "======================\n";
    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    Server server;
    server.initialize(atoi(argv[1]));
}
