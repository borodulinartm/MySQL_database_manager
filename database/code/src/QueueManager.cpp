#include "TableManager.h"

QueueManager::QueueManager() {
}

QueueManager::QueueManager(queue _my_queue) {
}

bool QueueManager::add(std::string data) {
    return false;
}

std::string QueueManager::get(int id) {
    return std::string();
}

bool QueueManager::erase(int id) {
    return false;
}

queue QueueManager::get_queue() const {
    return my_queue;
}

