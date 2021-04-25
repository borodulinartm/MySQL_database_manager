#include <iostream>
#include "DatabaseManager.h"

int main() {
    DatabaseManager databaseManager;
    bool res = databaseManager._connectToUser();
    if (res) {
        databaseManager.create_db();
    }
    return 0;
}