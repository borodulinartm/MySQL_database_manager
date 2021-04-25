#include "TableManager.h"

LocationManager::LocationManager() {
}

LocationManager::LocationManager(location _) {
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
