#include "TableManager.h"

ClientManager::ClientManager() {
};

ClientManager::ClientManager(client _my_client) {
}

bool ClientManager::add(std::string data) {
    return true;
}

std::string ClientManager::get(int id) {
    return std::string();
}

bool ClientManager::erase(int id) {
    return true;
}

std::string ClientManager::to_string() {
    return std::string();
}

void ClientManager::from_string(std::string string) {
}

client ClientManager::get_client() const {
    return my_client;
}

