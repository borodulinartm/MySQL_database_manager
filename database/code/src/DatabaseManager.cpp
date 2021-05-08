#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(): connection(nullptr), statement(nullptr), resultSet(nullptr), is_connected_to_user(
        false), is_connected_to_database(false), preparedStatement(nullptr) {
    driver = sql::mysql::get_driver_instance();
}

DatabaseManager::~DatabaseManager() {
    if (is_connected_to_user) {
        _disconnectToUser();
    }

    if (connection != nullptr) {
        delete connection;
        connection = nullptr;
    }

    if (statement != nullptr) {
        delete statement;
        statement = nullptr;
    }

    if (resultSet != nullptr) {
        delete resultSet;
        resultSet = nullptr;
    }
}

bool DatabaseManager::_connectToUser() {
    try {
        connection = driver->connect(ADDRESS, USER_NAME, PASSWORD);
        std::cout << "CONNECT: SUCCESS\n";
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
        return false;
    }
    is_connected_to_user = true;
    return is_connected_to_user;
}

bool DatabaseManager::_disconnectToUser() {
    try {
        connection->close();
        std::cout << "DICONNECT: SUCCESS\n";
        return true;
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
    }

    return false;
}

void DatabaseManager::PrintError(sql::SQLException &exception, std::string function, int line) {
    std::cerr << "# ERROR: SQLException in " << __FILE__;
    std::cerr << "(FUNCTION: " << function << ") on line " << line << std::endl;
    std::cerr << "Info: " << exception.what() << std::endl;
    std::cerr << "Code: " << exception.getErrorCode() << std::endl;
    std::cerr << "SQLState: " << exception.getSQLState() << std::endl;
}

// Database functions
bool DatabaseManager::is_connected_to_db() const {
    return is_connected_to_database;
}

bool DatabaseManager::connect_to_db() {
    if (!is_connected_to_user) {
        _connectToUser();
    }

    try {
        connection->setSchema(DATABASE_NAME);
        is_connected_to_database = true;
        return is_connected_to_database;
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
    }

    return false;
}

bool DatabaseManager::create_db() {
    query = "CREATE DATABASE ";
    query += DATABASE_NAME;

    if (!is_connected_to_user) {
        _connectToUser();
    }

    try {
        statement = connection->createStatement();
        statement->execute(query);
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
        return false;
    }
    return true;
}

// Проверка на существование базы данных
bool DatabaseManager::is_db_exists() {
    if (!is_connected_to_database) {
        connect_to_db();
    }

    try {
        query = "SHOW DATABASES";
        statement = connection->createStatement();
        resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            std::string database_name = resultSet->getString("Database");
            if (database_name == DATABASE_NAME) {
                return true;
            }
        }
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
    }

    return false;
}

bool DatabaseManager::is_table_exists(const std::string& table) {
    if (!is_connected_to_database) {
        connect_to_db();
    }

    try {
        query = "SHOW TABLES";
        statement = connection->createStatement();
        resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            std::string table_name = resultSet->getString("Tables_in_testdb");
            if (table_name == table) {
                return true;
            }
        }
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
    }

    return false;
}

// Создаёт таблицу
bool DatabaseManager::create_table(const std::string& table_name,
                                   const std::vector<std::pair<std::string, std::string>>& columns) {
    if (!is_connected_to_database) {
        connect_to_db();
    }

    try {
        query = "CREATE TABLE " + table_name + "(";
        for(size_t i = 0; i < columns.size(); ++i) {
            query += columns[i].first + " " + columns[i].second;
            if (i != columns.size() - 1) {
                query += ", ";
            }
        }

        query += ")";

        statement = connection->createStatement();
        statement->execute(query);

        return true;
    } catch(sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
    }

    return false;
}

// Вставка данных в таблицу (будет работать для любого типа таблицы)
bool DatabaseManager::insert_data(const std::string& table_name, std::vector<std::string> &cols, std::vector<std::string> &data,
                                  bool ignore_first) {
    try {
        query = "INSERT INTO " + table_name + "(";
        for(size_t i = ignore_first; i < cols.size(); ++i) {
            query += cols[i];
            if (i != cols.size() - 1) {
                query += ",";
            }
        }

        query += ") VALUES (";
        for(size_t i = ignore_first; i < data.size(); ++i) {
            if (is_digit(data[i])) {
                query += data[i];
            } else {
                query += "\"" + data[i] + "\"";
            }

            if (i != data.size() - 1) {
                query += ",";
            }
        }

        query += ")";

        statement = connection->createStatement();
        statement->execute(query);

        return true;
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
    }

    return false;
}

bool DatabaseManager::is_digit(std::string &str) {
    return !str.empty() && std::find_if(
        str.begin(), str.end(), [](char c) {
            return !std::isdigit(c);
        }
    ) == str.end();
}

// Извлечение данных
std::vector<std::vector<std::string>> DatabaseManager::get_data(const std::string &table_name,
                                        std::vector<std::string> cols) {
    if (!is_connected_to_database) {
        connect_to_db();
    }

    std::vector<std::vector<std::string>> data;
    try {
        query = "SELECT * FROM " + table_name;

        statement = connection->createStatement();
        resultSet = statement->executeQuery(query);

        std::vector<std::string> row;

        while (resultSet->next()) {
            for(auto &col : cols) {
                row.push_back(resultSet->getString(col));
            }

            data.push_back(row);
            row.clear();
        }
        return data;
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
    }

    return data;
}

std::vector<std::vector<std::string>> DatabaseManager::get_data(const std::string &table_name,
                                                                std::vector<std::string> &cols, std::vector<std::pair<std::string, std::string>> condition) {
    if (!is_connected_to_database) {
        connect_to_db();
    }

    std::vector<std::vector<std::string>> data;
    try {
       query = "SELECT * FROM " + table_name + " WHERE ";
       for (size_t i = 0; i < condition.size(); ++i) {
           query += condition[i].first + "=";
           if (is_digit(condition[i].second)) {
               query += condition[i].second;
           } else {
               query += "\"" + condition[i].second + "\"";
           }

           if (i != condition.size() - 1) {
               query += " AND ";
           }
       }

       statement = connection->createStatement();
       resultSet = statement->executeQuery(query);

       std::vector<std::string> row;
       while (resultSet->next()) {
           for(auto &column: cols) {
               row.push_back(resultSet->getString(column));
           }

           data.push_back(row);
           row.clear();
       }
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FILE__, __LINE__);
    }

    return data;
}

bool DatabaseManager::delete_data(std::string &table_name, int id) {
    if (!is_connected_to_database) {
        connect_to_db();
    }

    try {
        query = "DELETE FROM " + table_name + " WHERE id=" + std::to_string(id);

        preparedStatement = connection->prepareStatement(query);
        preparedStatement->executeUpdate();

        return true;
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
    }

    return false;
}

bool DatabaseManager::update_data(std::string &table_name, std::vector<std::pair<std::string, std::string>> &val,
                                  std::vector<std::pair<std::string, std::string>> columns) {
    if (!is_connected_to_database) {
        connect_to_db();
    }

    try {
        query = "UPDATE " + table_name + " SET ";
        for(size_t i = 0; i < val.size(); ++i) {
            query += val[i].first + "=";
            if (is_digit(val[i].second)) {
                query += val[i].second;
            } else {
                query += "\"" + val[i].second + "\"";
            }

            if (i != val.size() - 1) {
                query += ", ";
            }
        }

        query += " WHERE ";
        for(size_t i = 0; i < columns.size(); ++i) {
            if (is_digit(columns[i].second)) {
                query += columns[i].first + "=" + columns[i].second;
            } else {
                query += columns[i].first + "=" + "\"" + columns[i].second + "\"";
            }

            if (i != columns.size() - 1) {
                query += " AND ";
            }
        }

        preparedStatement = connection->prepareStatement(query);
        preparedStatement->executeUpdate();

        return true;
    } catch (sql::SQLException &exception) {
        PrintError(exception, __FUNCTION__, __LINE__);
    }

    return false;
}
