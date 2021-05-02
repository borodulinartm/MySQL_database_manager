#include "TableManager.h"

ListFoodManager::ListFoodManager(): table_name("list_food") {
}

ListFoodManager::ListFoodManager(list_food _my_list_food): my_list_food(_my_list_food),
            table_name("list_food") {
}

bool ListFoodManager::add(std::string data) {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }

    if (!dbManager.is_table_exists(table_name)) {
        auto cols = list_food::get_cols_sql();
        dbManager.create_table(table_name, cols);
    }

    auto res = to_vector();
    dbManager.insert_data(table_name, res);

    return true;
}

bool ListFoodManager::erase(int id) {
    return dbManager.delete_data(table_name, id);
}

list_food ListFoodManager::get_list_food() {
    return my_list_food;
}

std::vector<std::vector<std::string>> ListFoodManager::get(int id) {
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
            table_name, list_food::get_cols()
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

bool ListFoodManager::update(int id, std::vector<std::pair<std::string, std::string>> &val) {
    return dbManager.update_data(table_name, val, id);
}
