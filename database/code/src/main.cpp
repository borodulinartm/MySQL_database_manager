#include <iostream>
#include "DatabaseManager.h"
#include "TableManager.h"

int main() {
    DatabaseManager databaseManager;
    ClientManager clientManager(databaseManager);

    std::string data = "NDJE";
    clientManager.add(data);
    return 0;
}