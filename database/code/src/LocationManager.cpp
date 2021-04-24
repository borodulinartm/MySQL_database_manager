#include "TableManager.h"

LocationManager::LocationManager() {
    DatabaseManager dbManager;
//    if (dbManager.create_db()) {
//        std::cout << "SUCCESS CREATE DATABASE\n";
//    }

    if (!is_db_connected()) {
        bool res = dbManager.connect_to_db();
        if (res) {
            std::cout << "Connected";
        }
    }
}

LocationManager::LocationManager(const location& _my_location) {
}

bool LocationManager::add(std::string data) {
    return false;
}

std::string LocationManager::get(int id) {
    return std::string();
}

bool LocationManager::erase(int id) {
    return false;
}

std::string LocationManager::to_string() {
    return std::string();
}

void LocationManager::from_string(std::string string) {
}

location LocationManager::get_location() const {
    return my_location;
}
