#include "TableManager.h"

OrderManager::OrderManager() {
}

OrderManager::OrderManager(order my_order) {
}

bool OrderManager::add(std::string data) {
    return false;
}

std::string OrderManager::get(int id) {
    return std::string();
}

bool OrderManager::erase(int id) {
    return false;
}

std::string OrderManager::to_string() {
    return std::string();
}

void OrderManager::from_string(std::string string) {
}

order OrderManager::get_order() const {
    return my_order;
}
