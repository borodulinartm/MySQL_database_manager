#ifndef UNTITLED_DB_MANAGER_H
#define UNTITLED_DB_MANAGER_H

#include "IDatabaseManager.h"
#include "Data.h"

#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

#include <iostream>
#include <string>

#define ADDRESS "localhost"
#define USER_NAME "artem"
#define PASSWORD "!School211410l"
#define DATABASE_NAME "testdb"


class DatabaseManager: public IDatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();

    bool connect_to_db() override;
    bool create_db() override;
    bool is_db_exists() override;

    bool is_connected_to_db() const;

private:

    sql::Driver *driver;
    sql::Connection *connection;
    sql::Statement *statement;
    sql::ResultSet *resultSet;
    bool is_connected_to_user;

    bool is_connected_to_database;
    std::string query;

    void PrintError(sql::SQLException &exception);
    void SetQuery(const std::string& _query, bool add_database_name);
    bool _connectToUser();
    bool _disconnectToUser();
};

#endif //  UNTITLED_DB_MANAGER_H
