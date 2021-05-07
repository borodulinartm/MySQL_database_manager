#include "TableManager.h"

CafeManager::CafeManager(const DatabaseManager& _dbManager, cafe _my_cafe):
    table_name("cafe"), dbManager(_dbManager), my_cafe(std::move(_my_cafe)) {
}

CafeManager::CafeManager(cafe _my_cafe): table_name("cafe"), my_cafe(std::move(_my_cafe)) {
}

bool CafeManager::add() {
    check_access();

    if (!dbManager.is_table_exists(table_name)) {
        std::cout << "TABLE NOT EXIST\n";
        auto cols = my_cafe.get_cols_sql();
        dbManager.create_table(table_name, cols);
    }

    auto res = to_vector();
    dbManager.insert_data(table_name, res);

    return true;
}

bool CafeManager::erase(int id) {
    check_access();
    return dbManager.delete_data(table_name, id);
}

cafe CafeManager::get_cafe() const {
    return my_cafe;
}

std::vector<std::vector<std::string>> CafeManager::get(int id) {
    check_access();
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
            table_name, my_cafe.get_cols()
    );

    return to_return;
}

bool CafeManager::update(int id, std::vector<std::pair<std::string, std::string>> &val) {
    check_access();
    return dbManager.update_data(table_name, val, id);
}

std::vector<std::string> CafeManager::to_vector() {
    std::vector<std::string> to_return = {
            std::to_string(my_cafe.id_cafe),
            std::to_string(my_cafe.id_location),
            std::to_string(my_cafe.id_food),
            std::to_string(my_cafe.count_food)
    };

    return to_return;
}

void CafeManager::check_access() {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }
}
