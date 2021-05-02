#include <iostream>
#include "DatabaseManager.h"
#include "TableManager.h"

int main() {
    DatabaseManager databaseManager;
    client cl = {1, "Artem", "@bus", "thth1234", 1};
    list_food lf = {1, 1, 3, 100};

    ClientManager clientManager(cl);
    ListFoodManager listFoodManager(lf);

    clientManager.add("frfrf");
    listFoodManager.add("ggggggt");

    auto big_data = clientManager.get(0);
    auto big_data_2 = listFoodManager.get(0);
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

    data_to_update.emplace_back("name", "Artemida");
    data_to_update.emplace_back("login", "@bbbbus");

    data_to_update_2.emplace_back("count_buying", std::to_string(333));

    clientManager.update(1, data_to_update);
    listFoodManager.update(1, data_to_update_2);
    return 0;
}