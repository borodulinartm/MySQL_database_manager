#ifndef UNTITLED_DB_MANAGER_H
#define UNTITLED_DB_MANAGER_H

#include "IDatabaseManager.h"
#include "Data.h"

#include <iostream>

class DatabaseManager: public IDatabaseManager {
protected:
    bool connect_to_db() override;
    bool disconnect_to_db() override;
    bool create_db() override;
    bool is_db_exists() override;
};

#endif //  UNTITLED_DB_MANAGER_H
