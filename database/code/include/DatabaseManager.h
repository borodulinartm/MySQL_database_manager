#ifndef UNTITLED_DB_MANAGER_H
#define UNTITLED_DB_MANAGER_H

#include "IDatabaseManager.h"
#include "Data.h"

#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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

    bool insert_data(const std::string& table_name, std::vector<std::string> &data) override;

    bool is_table_exists(const std::string& table);
    bool create_table(const std::string& table_name, const std::vector<std::pair<std::string, std::string>>& columns);

private:
    // Указатели, которые нужно будет превратить в smart pointers
    sql::Driver *driver;
    sql::Connection *connection;
    sql::Statement *statement;
    sql::ResultSet *resultSet;
    sql::PreparedStatement *preparedStatement;

    bool is_connected_to_user;
    bool is_connected_to_database;
    std::string query;

    void PrintError(sql::SQLException &exception);
    void SetQuery(const std::string& _query, bool add_database_name);
    bool _connectToUser();
    bool _disconnectToUser();
    bool is_digit(std::string &str);
};

#endif //  UNTITLED_DB_MANAGER_H
