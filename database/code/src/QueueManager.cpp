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

std::string QueueManager::to_string() {
    return std::string();
}

void QueueManager::from_string(std::string string) {
}

queue QueueManager::get_queue() const {
    return my_queue;
}

