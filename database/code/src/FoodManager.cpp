#include "TableManager.h"

FoodManager::FoodManager() {
}

FoodManager::FoodManager(food m) {
}

bool FoodManager::add(std::string data) {
    return false;
}

std::string FoodManager::get(int id) {
    return std::string();
}

bool FoodManager::erase(int id) {
    return false;
}

std::string FoodManager::to_string() {
    return std::string();
}

void FoodManager::from_string(std::string string) {
}

food FoodManager::get_food() const {
    return my_food;
}