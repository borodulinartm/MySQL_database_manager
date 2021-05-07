#include <iostream>
#include "DatabaseManager.h"
#include "TableManager.h"

int main() {
    DatabaseManager databaseManager;
    supplier cl(1,2, "Vasya", "@bus", "dedf", 2);
    food f(1, "Burger", 100, 0);

    SupplierManager supplierManager(cl);
    FoodManager foodManager(f);

    supplierManager.add("frfrf");
    foodManager.add("ggggggt");

    auto big_data = supplierManager.get(0);
    auto big_data_2 = foodManager.get(0);
    for(auto & i : big_data) {
        for(auto & j : i) {
            std::cout << j << " ";
        }

        std::cout << std::endl;
    }

    for(auto & i : big_data_2) {
        for(auto & j : i) {
            std::cout << j << " ";
        }

        std::cout << std::endl;
    }

    std::vector<std::pair<std::string, std::string>> data_to_update;
    std::vector<std::pair<std::string, std::string>> data_to_update_2;

    data_to_update.emplace_back("name", "ARTEM");
    data_to_update.emplace_back("login", "@bbbbus");

    data_to_update_2.emplace_back("cost", std::to_string(3333));

    supplierManager.update(1, data_to_update);
    foodManager.update(1, data_to_update_2);
    return 0;
}