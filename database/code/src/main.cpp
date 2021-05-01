#include <iostream>
#include "DatabaseManager.h"
#include "TableManager.h"

int main() {
    DatabaseManager databaseManager;
    client cl = {1, "Artem", "@bus", "thth1234", 1};
    ClientManager clientManager(cl);

    clientManager.add("hbfr");
    return 0;
}