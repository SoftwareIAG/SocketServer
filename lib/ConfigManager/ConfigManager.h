#include <fstream>
#include <iostream>
#include "../HashTable/HashTable.h"

#ifndef SOCKET_SERVER_CONFIG_MANAGER_H
#define SOCKET_SERVER_CONFIG_MANAGER_H

class ConfigManager {
public:
    std::unordered_map<std::string, std::string> values;
    void initialize();
    std::string get(std::string key);
};

#endif //SOCKET_SERVER_CONFIG_MANAGER_H
