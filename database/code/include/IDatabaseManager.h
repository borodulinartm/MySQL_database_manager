#ifndef UNTITLED_MY_INTERFACE_H
#define UNTITLED_MY_INTERFACE_H

#include <string>
#include <mysql_connection.h>
#include "Data.h"

#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#define ADDRESS "localhost"
#define USER_NAME "artem"
#define PASSWORD "!School211410l"
#define DATABASE_NAME "testdb"

// Центральный интерфейс для работы с БД
class IDatabaseManager {
protected:
    // Методы для БД
    virtual bool connect_to_db() = 0;
    virtual bool create_db() = 0;
    virtual bool is_db_exists() = 0;
    virtual bool is_table_exists(const std::string& table) = 0;
    virtual bool create_table(const std::string& table_name, const std::vector<std::pair<std::string, std::string>>& columns) = 0;

    virtual bool insert_data(const std::string& table_name, std::vector<std::string> &data) = 0;
    virtual std::vector<std::vector<std::string>> get_data(const std::string &table_name, std::vector<std::string> cols) = 0;
    virtual bool delete_data(std::string &table_name, int id) = 0;
    virtual bool update_data(std::string &table_name, std::vector<std::pair<std::string, std::string>> &val, int id) = 0;
    virtual bool update_data(std::string &table_name, std::vector<std::pair<std::string, std::string>> &val,
                             std::vector<std::pair<std::string, std::string>> columns) = 0;
};

#endif //UNTITLED_MY_INTERFACE_H
