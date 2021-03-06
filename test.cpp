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

    std::cout << "=======================" << std::endl;
    std::cout << "= ConfigManager Tests =" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "                       " << std::endl;

    // ConfigManager Testing
    configManager->initialize();
    assert(configManager->get("ENV") == "LOCAL");
    std::cout << "configManager->get('ENV') returns 'LOCAL' as expected." << std::endl;
    assert(configManager->values["ENV"] == "LOCAL");
    std::cout << "configManager->values['ENV'] returns 'LOCAL' as expected." << std::endl;

    std::cout << "                   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "= HashTable Tests =" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "                   " << std::endl;

    // HashTable Testing
    HashTable hashTable;
    std::string identifier = "ABC";
    std::string value = "DEF";
    hashTable.insert(identifier, value);
    std::cout << "hashTable.insert('ABC', 'DEF') executed." << std::endl;
    hashTable.render();
    std::cout << "hashTable.render() executed." << std::endl;

    assert(hashTable.get(identifier) == value);
    std::cout << "hashTable.get('ABC') returns 'DEF' as expected." << std::endl;
    assert(hashTable.exists(identifier) == 1);
    std::cout << "hashTable.exists('ABC') returns 'true' as expected." << std::endl;
    hashTable.remove(identifier);
    std::cout << "hashTable.remove('ABC') executed." << std::endl;
    assert(hashTable.exists(identifier) == 0);
    std::cout << "hashTable.exists('ABC') returns 'false' as expected." << std::endl;

    std::cout << "                  " << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "= LinkList Tests =" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "                  " << std::endl;

    // LinkList Testing
    LinkList linkList;
    linkList.insert(10);
    std::cout << "linkList.insert(10) executed." << std::endl;
    linkList.insert(20);
    std::cout << "linkList.insert(20) executed." << std::endl;
    linkList.insert(30);
    std::cout << "linkList.insert(30) executed." << std::endl;
    linkList.render();
    std::cout << "linkList.render() executed." << std::endl;
    assert(linkList.search(10) == 1);
    std::cout << "linkList.search(10) returns 'true' as expected." << std::endl;
    linkList.remove(10);
    std::cout << "linkList.remove(10) executed." << std::endl;
    assert(linkList.search(10) == 0);
    std::cout << "linkList.search(10) returns 'false' as expected." << std::endl;
    assert(linkList.search(20) == 1);
    std::cout << "linkList.search(20) returns 'true' as expected." << std::endl;
    assert(linkList.search(30) == 1);
    std::cout << "linkList.search(30) returns 'true' as expected." << std::endl;
}
