#include <utility>

#include "TableManager.h"

LocationManager::LocationManager(location _my_location): table_name("location"),
    my_location(std::move(_my_location)) {
}

LocationManager::LocationManager(const DatabaseManager& _dbManager, location _my_location):
        dbManager(_dbManager), my_location(std::move(_my_location)), table_name("location") {
}

bool LocationManager::add(std::string data) {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }

    if (!dbManager.is_table_exists(table_name)) {
        std::cout << "TABLE NOT EXIST\n";
        auto cols = my_location.get_cols_sql();
        dbManager.create_table(table_name, cols);
    }

    auto res = to_vector();
    dbManager.insert_data(table_name, res);

    return true;
}

bool LocationManager::erase(int id) {
    return dbManager.delete_data(table_name, id);
}

location LocationManager::get_location() const {
    return my_location;
}

std::vector<std::vector<std::string>> LocationManager::get(int id) {
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
            table_name, my_location.get_cols()
    );

    return to_return;
}

bool LocationManager::update(int id, std::vector<std::pair<std::string, std::string>> &val) {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }

    return dbManager.update_data(table_name, val, id);
}

std::vector<std::string> LocationManager::to_vector() {
    std::vector<std::string> to_return = {
            std::to_string(my_location.id_location),
            my_location.type_building,
            std::to_string(my_location.floor)
    };

    return to_return;
}
