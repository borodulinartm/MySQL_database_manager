#include "TableManager.h"

OrderManager::OrderManager(const DatabaseManager& _dbManager, order _my_order):
    table_name("booking"), dbManager(_dbManager), my_order(std::move(_my_order)) {
}

OrderManager::OrderManager(order _my_order): table_name("booking"), my_order(std::move(_my_order)) {
}

bool OrderManager::add() {
    check_access();

    if (!dbManager.is_table_exists(table_name)) {
        std::cout << "TABLE NOT EXIST\n";
        auto cols = my_order.get_cols_sql();
        dbManager.create_table(table_name, cols);
    }

    auto res = to_vector();
    auto cols = my_order.get_cols();

    dbManager.insert_data(table_name, cols, res);

    return true;
}

bool OrderManager::erase(int id) {
    check_access();
    return dbManager.delete_data(table_name, id);
}

order OrderManager::get_order() const {
    return my_order;
}

std::vector<std::vector<std::string>> OrderManager::get() {
    check_access();
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
            table_name, my_order.get_cols()
    );

    return to_return;
}

bool OrderManager::update(std::vector<std::pair<std::string, std::string>> &val,
                          std::vector<std::pair<std::string, std::string>> &columns) {
    check_access();
    return dbManager.update_data(table_name, val, columns);
}

std::vector<std::string> OrderManager::to_vector() {
    std::vector<std::string> to_return = {
            std::to_string(my_order.id_order),
            std::to_string(my_order.id_cafe),
            std::to_string(my_order.id_user),
            std::to_string(my_order.id_products),
            std::to_string(my_order.id_slot),
            std::to_string(my_order.total_cost),
            std::to_string(my_order.stage),
            std::to_string(my_order.id_supplier)
    };

    return to_return;
}

void OrderManager::check_access() {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }
}

bool OrderManager::add(order _order) {
    my_order = std::move(_order);
    return add();
}

DatabaseManager OrderManager::get_database_manager() const {
    return dbManager;
}
