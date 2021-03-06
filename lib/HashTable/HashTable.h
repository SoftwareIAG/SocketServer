#include <iostream>
#include <unordered_map>
#include <vector>

#ifndef SOCKET_SERVER_HASH_TABLE_H
#define SOCKET_SERVER_HASH_TABLE_H

class HashTable {
private:
    std::unordered_map<std::string, std::string> table;
public:
    std::string get(std::string &identifier);
    bool exists(std::string &identifier);
    void insert(std::string &identifier, std::string &value);
    void remove(std::string &identifier);
    void render();
};

#endif //SOCKET_SERVER_HASH_TABLE_H
