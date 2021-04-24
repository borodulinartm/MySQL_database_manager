#include "DatabaseManager.h"

bool DatabaseManager::connect_to_db() {
    std::cout << "Connected\n";
    return true;
}

bool DatabaseManager::disconnect_to_db() {
    std::cout << "Disconnected\n";
    return true;
}

bool DatabaseManager::create_db() {
    std::cout << "Created\n";
    return true;
}

bool DatabaseManager::is_db_exists() {
    return true;
}
