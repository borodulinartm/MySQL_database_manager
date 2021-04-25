#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() {
    driver = sql::mysql::get_driver_instance();
    connection = nullptr;
    is_connected_to_user = false;
}

DatabaseManager::~DatabaseManager() {
    if (is_connected_to_user) {
        _disconnectToUser();
    }

    if (connection != nullptr) {
        delete connection;
        connection = nullptr;
    }
}

bool DatabaseManager::_connectToUser() {
    try {
        connection = driver->connect(ADDRESS, USER_NAME, PASSWORD);
        std::cout << "CONNECT: SUCCESS\n";
    } catch (std::exception &exception) {
        std::cout << "Error: " << exception.what() << std::endl;
        return false;
    }
    is_connected_to_user = true;
    return is_connected_to_user;
}

bool DatabaseManager::_disconnectToUser() {
    try {
        connection->close();
        std::cout << "DICONNECT: SUCCESS\n";
        return true;
    } catch (std::exception &exception) {
        std::cout << "Error: " << exception.what() << std::endl;
    }

    return false;
}

bool DatabaseManager::connect_to_db() {
    std::cout << "Connected\n";
    return true;
}

bool DatabaseManager::disconnect_to_db() {
    std::cout << "Disconnected\n";
    return true;
}

bool DatabaseManager::create_db() {
    std::cout << "Created\n";
    return true;
}

bool DatabaseManager::is_db_exists() {
    return true;
}
