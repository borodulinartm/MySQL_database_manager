#ifndef UNTITLED_DB_MANAGER_H
#define UNTITLED_DB_MANAGER_H

#include "IDatabaseManager.h"

#include <iostream>
#include <string>
#include <vector>

class DatabaseManager: public IDatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();

    bool connect_to_db() override;
    bool create_db() override;

    bool is_db_exists() override;
    bool is_connected_to_db() const;

    bool insert_data(const std::string& table_name, std::vector<std::string> &cols, std::vector<std::string> &data,
                     bool ignore_first = false) override;
    std::vector<std::vector<std::string>> get_data(const std::string &table_name, std::vector<std::string> cols) override;
    std::vector<std::vector<std::string>> get_data(const std::string &table_name,
                                                   std::vector<std::string> &cols, std::vector<std::pair<std::string, std::string>> condition) override;
    bool delete_data(std::string &table_name, int id) override;
    bool update_data(std::string &table_name, std::vector<std::pair<std::string, std::string>> &val,
                     std::vector<std::pair<std::string, std::string>> columns) override;

    bool is_table_exists(const std::string& table) override;
    bool create_table(const std::string& table_name, const std::vector<std::pair<std::string, std::string>>& columns) override;

    bool is_digit(std::string &str);
private:
    // Указатели, которые не работают в режиме smart pointers
    sql::Driver *driver;
    sql::Connection *connection;
    sql::Statement *statement;
    sql::ResultSet *resultSet;

    sql::PreparedStatement *preparedStatement;
    bool is_connected_to_user;
    bool is_connected_to_database;

    std::string query;
    void PrintError(sql::SQLException &exception, const std::string& function, int line);
    bool _connectToUser();
    bool _disconnectToUser();
};

#endif //  UNTITLED_DB_MANAGER_H
