#include <iostream>
#include <unordered_map>
#include <vector>
#include "../HashNode/HashNode.h"

#ifndef SOCKET_SERVER_HASH_TABLE_H
#define SOCKET_SERVER_HASH_TABLE_H

class HashTable {
private:
    std::unordered_map<int, HashNode> table;
    static int hash(char* key);
public:
    HashNode get(char* key);
    bool exists(char* key);
    void insert(char* key, char* value);
    void remove(char* key);
    void render();
};

#endif //SOCKET_SERVER_HASH_TABLE_H
