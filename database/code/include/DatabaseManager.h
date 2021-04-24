#ifndef UNTITLED_DB_MANAGER_H
#define UNTITLED_DB_MANAGER_H

#include "IDatabaseManager.h"
#include "Data.h"

#include <iostream>
#include <string>
#include <mysql/mysql.h>

#define DATABASE_NAME "testdb"

class DatabaseManager: public IDatabaseManager {
protected:
    bool connect_to_db() override;
    bool disconnect_to_db() override;
    bool create_db() override;
    bool is_db_exists() override;

private:
    MYSQL *conn_ptr;
    std::string query;
};

#endif //  UNTITLED_DB_MANAGER_H
