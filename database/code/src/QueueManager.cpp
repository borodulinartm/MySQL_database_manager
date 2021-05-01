#include "TableManager.h"

QueueManager::QueueManager() {
}

QueueManager::QueueManager(queue _my_queue) {
}

bool QueueManager::add(std::string data) {
    return false;
}

bool QueueManager::erase(int id) {
    return false;
}

queue QueueManager::get_queue() const {
    return my_queue;
}

std::vector<std::vector<std::string>> QueueManager::get(int id) {
    return std::vector<std::vector<std::string>>();
}
