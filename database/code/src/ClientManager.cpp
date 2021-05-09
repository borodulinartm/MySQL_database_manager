#include "TableManager.h"
#include "Data.h"

ClientManager::ClientManager(const DatabaseManager& _dbManager, client _my_client): dbManager(_dbManager),
                table_name("clients"), my_client(std::move(_my_client)) {
};

ClientManager::ClientManager(client _my_client): table_name("clients"),
                my_client(std::move(_my_client)) {
}

ClientManager::ClientManager(): table_name("clients") {
    my_client.user_id = 0;
    my_client.peopleInfo.name = my_client.peopleInfo.login = my_client.peopleInfo.password = "";
    my_client.peopleInfo.registration_code = 0;
}

bool ClientManager::add() {
    check_access();

    if (!dbManager.is_table_exists(table_name)) {
        std::cout << "TABLE NOT EXIST\n";
        auto cols = my_client.get_cols_sql();
        dbManager.create_table(table_name, cols);
    }

    auto res = to_vector();
    auto cols = my_client.get_cols();

    dbManager.insert_data(table_name, cols, res, true);

    return true;
}

std::vector<std::vector<std::string>> ClientManager::get() {
    check_access();
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
         table_name, my_client.get_cols()
    );

    return to_return;
}

std::vector<std::vector<std::string>> ClientManager::get(std::vector<std::pair<std::string, std::string>> condition) {
    check_access();

    auto cols = my_client.get_cols();
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
            table_name,cols,std::move(condition)
    );

    return to_return;
}

bool ClientManager::erase(int id) {
    check_access();
    return dbManager.delete_data(table_name, id);
}

std::vector<std::string> ClientManager::to_vector() {
    std::vector<std::string> to_return = {
            std::to_string(my_client.user_id),
            my_client.peopleInfo.name,
            my_client.peopleInfo.login,
            my_client.peopleInfo.password,
            std::to_string(my_client.peopleInfo.registration_code)
    };

    return to_return;
}

bool ClientManager::update(std::vector<std::pair<std::string, std::string>> &val,
                           std::vector<std::pair<std::string, std::string>> &columns) {
    check_access();
    return dbManager.update_data(table_name, val, columns);
}

void ClientManager::check_access() {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }
}

bool ClientManager::add(client _client) {
    my_client = std::move(_client);
    return add();
}

client ClientManager::get_client() const {
    return my_client;
}

DatabaseManager ClientManager::get_database_manager() const {
    return dbManager;
}

void ClientManager::set_client(client _client) {
    my_client = std::move(_client);
}

