#include "ConfigManager.h"

/**
 * Initialize config manager.
 *
 */
void ConfigManager::initialize() {
    std::cout << "[ConfigManager::initialize] Config Manager will be initialized ... \n";
    std::fstream file("config.cfg");
    std::string key;
    std::string value;
    while (file >> key >> value) {
        char* char_key = const_cast<char*>(key.c_str());
        char* char_value = const_cast<char*>(value.c_str());
        std::cout << key << " " << value << std::endl;
        configTable.insert(char_key, char_value);
    }
    std::cout << "[ConfigManager::initialize] Config Manager was initialized ... \n";
}

/**
 * Get config value.
 *
 * @param key
 * @return
 */
char* ConfigManager::get(const std::string& key) {
    std::cout << "[ConfigManager::get] Config Manager will be get value ... \n";
    char* char_key = const_cast<char*>(key.c_str());
    char* char_value = configTable.get(char_key).value;
    std::cout << "[ConfigManager::get] Config Manager will be get value ... \n";
    return char_value;
}
