//
// Created by zen on 02-03-21.
//

#ifndef SOCKETSERVER_HASHTABLE_H
#define SOCKETSERVER_HASHTABLE_H

typedef struct HashTableItem HashTableItem;

struct HashTableItem {
    char* key;
    char* value;
};

typedef struct HashTableStorage HashTableStorage;

struct HashTableStorage {
    HashTableItem** items;
    int size;
    int count;
};


class HashTable {
public:
    unsigned long hash(char * string);
    void insert(HashTableStorage* table, char* key, char* value);



};


#endif //SOCKETSERVER_HASHTABLE_H
