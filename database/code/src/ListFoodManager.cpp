#include "TableManager.h"

ListFoodManager::ListFoodManager() {
}

ListFoodManager::ListFoodManager(std::vector<list_food> _my_list_food) {
}

bool ListFoodManager::add(std::string data) {
    return false;
}

std::string ListFoodManager::get(int id) {
    return std::string();
}

bool ListFoodManager::erase(int id) {
    return false;
}

std::string ListFoodManager::to_string() {
    return std::string();
}

void ListFoodManager::from_string(std::string string) {
}

std::vector<list_food> ListFoodManager::get_list_food() {
    return my_list_food;
}
