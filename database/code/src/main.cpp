#include <iostream>
#include "DatabaseManager.h"
#include "TableManager.h"

int main() {
    DatabaseManager databaseManager;
    supplier cl(1,2, "Vasya", "@bus", "dedf", 2);
    order o(0,2,3,4,5,6,7,8);

    SupplierManager supplierManager(cl);
    OrderManager orderManager(o);

    supplierManager.add("frfrf");
    orderManager.add("ggggggt");

    auto big_data = supplierManager.get(0);
    auto big_data_2 = orderManager.get(0);
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

    data_to_update_2.emplace_back("id_slot", std::to_string(320));

    supplierManager.update(1, data_to_update);
    orderManager.update(0, data_to_update_2);
    return 0;
}