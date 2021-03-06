#include <cassert>
#include "main.h"
#include "lib/LinkList/LinkList.h"
#include "lib/HashTable/HashTable.h"
#include "lib/ConfigManager/ConfigManager.h"

/**
 * Test.
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[]) {
    // ConfigManager Testing
    configManager->initialize();
    assert(configManager->get("ENV") == "LOCAL");
    std::cout << "configManager->get('ENV') returns 'LOCAL' as expected." << std::endl;
    assert(configManager->values["ENV"] == "LOCAL");
    std::cout << "configManager->values['ENV'] returns 'LOCAL' as expected." << std::endl;

    // HashTable Testing
    HashTable hashTable;
    std::string identifier = "ABC";
    std::string value = "ABC";
    hashTable.insert(identifier, value);
    std::cout << "The list will be rendered:" << std::endl;
    hashTable.render();

    assert(hashTable.get(identifier) == value);
    assert(hashTable.exists(identifier) == 1);
    hashTable.remove(identifier);
    assert(hashTable.exists(identifier) == 0);
}
