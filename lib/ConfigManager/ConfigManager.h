#include <fstream>
#include <iostream>
#include "../HashTable/HashTable.h"

#ifndef SOCKET_SERVER_CONFIG_MANAGER_H
#define SOCKET_SERVER_CONFIG_MANAGER_H

class ConfigManager {
public:
    HashTable configTable;
    void initialize();
    char* get(const std::string& key);
};

#endif //SOCKET_SERVER_CONFIG_MANAGER_H
