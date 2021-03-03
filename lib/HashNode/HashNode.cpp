#include "HashNode.h"

/**
 * Set key in HashNode.
 *
 * @param key
 * @return void
 */
void HashNode::set_key(char *key) {
    this->key = key;
}

/**
 * Set value in HashNode.
 *
 * @param value
 * @return void
 */
void HashNode::set_value(char *value) {
    this->value = value;
}

/**
 * Set hash in HashNode.
 *
 * @param hash
 * @return void
 */
void HashNode::set_hash(int hash) {
    this->hash = hash;
}
