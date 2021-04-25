#include "TableManager.h"

ClientManager::ClientManager(DatabaseManager _dbManager) {
    dbManager = _dbManager;
};

ClientManager::ClientManager(client _my_client, DatabaseManager _dbManager): my_client(_my_client),
                            dbManager(_dbManager) {
}

ClientManager::ClientManager() {
    // Some data
}

bool ClientManager::add(std::string data) {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }

    std::cout << "ADDED\n";
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

