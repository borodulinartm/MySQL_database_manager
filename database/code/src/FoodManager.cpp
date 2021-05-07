#include "TableManager.h"

FoodManager::FoodManager(const DatabaseManager& _dbManager, food _my_food):
    table_name("food"), dbManager(_dbManager), my_food(std::move(_my_food)) {
}

FoodManager::FoodManager(food _my_food): table_name("food"),
     my_food(std::move(_my_food)) {
}

bool FoodManager::add(std::string data) {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }

    if (!dbManager.is_table_exists(table_name)) {
        std::cout << "TABLE NOT EXIST\n";
        auto cols = my_food.get_cols_sql();
        dbManager.create_table(table_name, cols);
    }

    auto res = to_vector();
    dbManager.insert_data(table_name, res);

    return true;
}

bool FoodManager::erase(int id) {
    return dbManager.delete_data(table_name, id);
}

food FoodManager::get_food() const {
    return my_food;
}

std::vector<std::vector<std::string>> FoodManager::get(int id) {
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
            table_name, my_food.get_cols()
    );

    return to_return;
}

bool FoodManager::update(int id, std::vector<std::pair<std::string, std::string>> &val) {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }

    return dbManager.update_data(table_name, val, id);
}

std::vector<std::string> FoodManager::to_vector() {
    std::vector<std::string> to_return = {
            std::to_string(my_food.id_food),
            my_food.name_eat,
            std::to_string(my_food.cost),
            std::to_string(my_food.where_use)
    };

    return to_return;
}
