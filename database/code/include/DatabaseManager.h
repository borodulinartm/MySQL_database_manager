#ifndef UNTITLED_DB_MANAGER_H
#define UNTITLED_DB_MANAGER_H

#include "IDatabaseManager.h"
#include "Data.h"

#include <iostream>
#include <string>
#include <mysql/mysql.h>

#define DATABASE_NAME "testdb"
#define ERROR_TITLE "An error occured: "

class DatabaseManager: public IDatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();
    void set_query(const std::string& _query);
    bool is_db_connected() const;

    bool connect_to_db() override;
    bool create_db() override;
    bool is_db_exists() override;

private:
    MYSQL *conn_ptr;
    std::string query;
    bool is_connected;

    bool connect_to_user();
};

#endif //  UNTITLED_DB_MANAGER_H
