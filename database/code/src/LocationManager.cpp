#include "TableManager.h"

LocationManager::LocationManager() {
}

LocationManager::LocationManager(location _) {
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
