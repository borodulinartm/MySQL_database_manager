#include "TableManager.h"

FoodManager::FoodManager() {
}

FoodManager::FoodManager(food m) {
}

bool FoodManager::add(std::string data) {
    return false;
}

bool FoodManager::erase(int id) {
    return false;
}

food FoodManager::get_food() const {
    return my_food;
}

std::vector<std::vector<std::string>> FoodManager::get(int id) {
    return std::vector<std::vector<std::string>>();
}
