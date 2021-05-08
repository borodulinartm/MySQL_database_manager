#include "TableManager.h"

ListFoodManager::ListFoodManager(const DatabaseManager& _dbManager, list_food _my_list_food):
    table_name("list_food"), dbManager(_dbManager), my_list_food(std::move(_my_list_food)) {
}

ListFoodManager::ListFoodManager(list_food _my_list_food): my_list_food(std::move(_my_list_food)),
            table_name("list_food") {
}

bool ListFoodManager::add() {
    check_access();

    if (!dbManager.is_table_exists(table_name)) {
        auto cols = my_list_food.get_cols_sql();
        dbManager.create_table(table_name, cols);
    }

    auto res = to_vector();
    auto cols = my_list_food.get_cols();

    dbManager.insert_data(table_name, cols, res);

    return true;
}

bool ListFoodManager::erase(int id) {
    check_access();
    return dbManager.delete_data(table_name, id);
}

list_food ListFoodManager::get_list_food() {
    return my_list_food;
}

std::vector<std::vector<std::string>> ListFoodManager::get(int id) {
    check_access();
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
            table_name, my_list_food.get_cols()
    );

    return to_return;
}

std::vector<std::string> ListFoodManager::to_vector() {
    std::vector<std::string> to_return = {
        std::to_string(my_list_food.id_food),
        std::to_string(my_list_food.id_products),
        std::to_string(my_list_food.count_buying),
        std::to_string(my_list_food.total_cost)
    };

    return to_return;
}

bool ListFoodManager::update(std::vector<std::pair<std::string, std::string>> &val,
                             std::vector<std::pair<std::string, std::string>> &columns) {
    check_access();
    return dbManager.update_data(table_name, val, columns);
}

void ListFoodManager::check_access() {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }
}

bool ListFoodManager::add(list_food _list_food) {
    my_list_food = std::move(_list_food);
    return add();
}

DatabaseManager ListFoodManager::get_database_manager() const {
    return dbManager;
}
