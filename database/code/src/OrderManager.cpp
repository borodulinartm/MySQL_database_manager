#include "TableManager.h"

OrderManager::OrderManager() {
}

OrderManager::OrderManager(order my_order) {
}

bool OrderManager::add(std::string data) {
    return false;
}

bool OrderManager::erase(int id) {
    return false;
}

order OrderManager::get_order() const {
    return my_order;
}

std::vector<std::vector<std::string>> OrderManager::get(int id) {
    return std::vector<std::vector<std::string>>();
}
