#include "TableManager.h"

LocationManager::LocationManager(location _my_location) {
}

LocationManager::LocationManager() {
}

bool LocationManager::add(std::string data) {
    return false;
}

bool LocationManager::erase(int id) {
    return false;
}

location LocationManager::get_location() const {
    return my_location;
}

std::vector<std::vector<std::string>> LocationManager::get(int id) {
    return std::vector<std::vector<std::string>>();
}

bool LocationManager::update(int id, std::vector<std::pair<std::string, std::string>> &val) {
    return false;
}
