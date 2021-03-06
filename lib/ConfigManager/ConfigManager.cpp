#include "ConfigManager.h"

/**
 * Initialize config manager.
 *
 */
void ConfigManager::initialize() {
    std::cout << "[ConfigManager::initialize] Config will be read ... " << std::endl;
    std::ifstream file("config.cfg");
    if (!file.good()) perror("File 'config.cfg' doesn't not exists in executable path");
    std::string key;
    std::string value;
    while (file >> key >> value) {
        values[key] = value;
    }
    std::cout << "[ConfigManager::initialize] Config was read ... " << std::endl;
}

/**
 * Get config value.
 *
 * @param key
 * @return
 */
std::string ConfigManager::get(std::string key) {
    return values[key];
}
