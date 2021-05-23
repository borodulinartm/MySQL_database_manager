#include <utility>

#include "TableManager.h"
#include "Data.h"

SupplierManager::SupplierManager(const DatabaseManager &_dbManager, supplier _my_supplier):
        dbManager(_dbManager), table_name("suppliers"), my_supplier(std::move(_my_supplier)) {
}

SupplierManager::SupplierManager(supplier _my_supplier): table_name("suppliers"),
                                                         my_supplier(std::move(_my_supplier)) {
}

SupplierManager::SupplierManager(): table_name("suppliers") {
    my_supplier.supplier_id = my_supplier.cafe_id = 0;
    my_supplier.peopleInfo.name = my_supplier.peopleInfo.login = my_supplier.peopleInfo.password = "";
    my_supplier.peopleInfo.registration_code = 0;
}

bool SupplierManager::add() {
    check_access();

    if (!dbManager.is_table_exists(table_name)) {
        std::cout << "TABLE NOT EXIST\n";
        auto cols = my_supplier.get_cols_sql();
        dbManager.create_table(table_name, cols);
    }

    auto res = to_vector();
    auto cols = my_supplier.get_cols();

    dbManager.insert_data(table_name, cols, res, true);

    return true;
}

std::vector<std::vector<std::string>> SupplierManager::get() {
    check_access();
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
            table_name, my_supplier.get_cols()
    );

    return to_return;
}

bool SupplierManager::erase(int id) {
    check_access();
    return dbManager.delete_data(table_name, id);
}

bool SupplierManager::update(std::vector<std::pair<std::string, std::string>> &val,
                             std::vector<std::pair<std::string, std::string>> &columns) {
    check_access();
    return dbManager.update_data(table_name, val, columns);
}

std::vector<std::string> SupplierManager::to_vector() {
    std::vector<std::string> to_return = {
            std::to_string(my_supplier.supplier_id),
            std::to_string(my_supplier.cafe_id),
            my_supplier.peopleInfo.name,
            my_supplier.peopleInfo.login,
            my_supplier.peopleInfo.password,
            std::to_string(my_supplier.peopleInfo.registration_code)
    };

    return to_return;
}

void SupplierManager::check_access() {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }
}

bool SupplierManager::add(supplier _supplier) {
    my_supplier = std::move(_supplier);
    return add();
}

supplier SupplierManager::get_supplier() const {
    return my_supplier;
}

DatabaseManager SupplierManager::get_database_manager() const {
    return dbManager;
}

void SupplierManager::set(supplier _supp) {
    my_supplier = std::move(_supp);
}

std::vector<std::vector<std::string>> SupplierManager::get(std::vector<std::pair<std::string, std::string>> condition) {
    check_access();

    auto cols = my_supplier.get_cols();
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
            table_name,cols,std::move(condition)
    );

    return to_return;
}
