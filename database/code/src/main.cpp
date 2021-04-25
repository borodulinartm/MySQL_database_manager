#include <iostream>
#include "DatabaseManager.h"

int main() {
    DatabaseManager databaseManager;
    bool res = databaseManager._connectToUser();
    std::cout << res << std::endl;
    return 0;
}