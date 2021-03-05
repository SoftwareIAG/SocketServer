#ifndef SOCKET_SERVER_HASH_NODE_H
#define SOCKET_SERVER_HASH_NODE_H

class HashNode {
public:
    void set_key(char* key);
    void set_value(char* value);
    void set_hash(int hash);
    char* key;
    char* value;
    int hash;
};

#endif //SOCKET_SERVER_HASH_NODE_H
