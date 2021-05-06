#include <utility>

#include "TableManager.h"
#include "Data.h"

ClientManager::ClientManager(const DatabaseManager& _dbManager, client _my_client): dbManager(_dbManager),
                table_name("clients"), my_client(std::move(_my_client)) {
};

ClientManager::ClientManager(client _my_client): table_name("clients"),
                my_client(std::move(_my_client)) {
}

bool ClientManager::add(std::string data) {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }

    if (!dbManager.is_table_exists(table_name)) {
        std::cout << "TABLE NOT EXIST\n";
        auto cols = client::get_cols_sql();
        dbManager.create_table(table_name, cols);
    }

    auto res = to_vector();
    dbManager.insert_data(table_name, res);

    return true;
}

std::vector<std::vector<std::string>> ClientManager::get(int id) {
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
         table_name, client::get_cols()
    );

    return to_return;
}

bool ClientManager::erase(int id) {
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

bool ClientManager::update(int id, std::vector<std::pair<std::string, std::string>> &val) {
    return dbManager.update_data(table_name, val, id);
}
