#include "HashTable.h"

/**
 * Insert key-value in HashTable.
 *
 * @param key
 * @param value
 * @return void
 */
void HashTable::insert(std::string &identifier, std::string &value) {
    table[identifier] = value;
}

/**
 * Remove key in HashTable.
 *
 * @param key
 * @return void
 */
void HashTable::remove(std::string &identifier) {
    if (exists(identifier)) {
        table.erase(identifier);
    }
}

/**
 * Render HashTable.
 *
 * @return void
 */
void HashTable::render() {
    for (auto& iterator: table) {
        std::cout << "Key: '" << iterator.first << "', Value: '" << iterator.second << "'" << std::endl;
    }
}

/**
 * Check key exists in HashTable.
 *
 * @param key
 * @return bool
 */
bool HashTable::exists(std::string &identifier) {
    bool exists = false;
    for (auto& iterator: table) {
        if (identifier == iterator.first)
            exists = true;
    }
    return exists;
}

/**
 * Get HashNode by key.
 *
 * @param key
 * @return HashNode
 */
std::string HashTable::get(std::string &identifier) {
    return table[identifier];
}
