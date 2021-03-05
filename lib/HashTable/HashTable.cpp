#include "HashTable.h"

/**
 * Get hash from key.
 *
 * @param key
 * @return int
 */
int HashTable::hash(char *key) {
    std::hash<std::string> hasher;
    auto hashed = hasher(key);
    return static_cast<int>(hashed);
}

/**
 * Insert key-value in HashTable.
 *
 * @param key
 * @param value
 * @return void
 */
void HashTable::insert(char* key, char* value) {
    int hashed = hash(key);
    HashNode entry = HashNode();
    entry.set_key(key);
    entry.set_value(value);
    entry.set_hash(hashed);
    table[hashed] = entry;
}

/**
 * Remove key in HashTable.
 *
 * @param key
 * @return void
 */
void HashTable::remove(char *key) {
    if (exists(key)) {
        int hashed = hash(key);
        table.erase(hashed);
    }
}

/**
 * Render HashTable.
 *
 * @return void
 */
void HashTable::render() {
    auto iterator = table.begin();
    while(++iterator != table.end())
    {
        HashNode hashNode = table[iterator->first];
        std::cout << "Hash: " << iterator->first << " Key: '" << hashNode.key << "' Value: '" << hashNode.value << "'" << std::endl;
    }
}

/**
 * Check key exists in HashTable.
 *
 * @param key
 * @return bool
 */
bool HashTable::exists(char *key) {
    int hashed = hash(key);
    HashNode entry = table[hashed];
    return entry.key != NULL;
}

/**
 * Get HashNode by key.
 *
 * @param key
 * @return HashNode
 */
HashNode HashTable::get(char *key) {
    int hashed = hash(key);
    return table[hashed];
}
