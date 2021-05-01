#include <iostream>
#include "DatabaseManager.h"
#include "TableManager.h"

int main() {

    DatabaseManager databaseManager;
    client cl = {1, "Artem", "@bus", "thth1234", 1};
    ClientManager clientManager(cl);

//    clientManager.add("frfrf");
    auto big_data = clientManager.get(0);
    for(auto & i : big_data) {
        for(auto & j : i) {
            std::cout << j << " ";
        }

        std::cout << std::endl;
    }

    clientManager.erase(1);
    return 0;
}