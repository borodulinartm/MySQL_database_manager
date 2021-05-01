#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(): connection(nullptr), statement(nullptr), resultSet(nullptr), is_connected_to_user(
        false), is_connected_to_database(false) {
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
        PrintError(exception);
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
        PrintError(exception);
    }

    return false;
}

void DatabaseManager::PrintError(sql::SQLException &exception) {
    std::cout << "# ERROR: SQLException in " << __FILE__;
    std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
    std::cout << "Info: " << exception.what() << std::endl;
    std::cout << "Code: " << exception.getErrorCode() << std::endl;
    std::cout << "SQLState: " << exception.getSQLState() << std::endl;
}

void DatabaseManager::SetQuery(const std::string& _query, bool add_database_name) {
    if (add_database_name) {
        query = _query + " " + DATABASE_NAME;
    } else {
        query = _query;
    }
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
        PrintError(exception);
    }

    return false;
}

bool DatabaseManager::create_db() {
    SetQuery("CREATE DATABASE", true);
    if (!is_connected_to_user) {
        _connectToUser();
    }

    try {
        statement = connection->createStatement();
        statement->execute(query);
    } catch (sql::SQLException &exception) {
        PrintError(exception);
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
        SetQuery("SHOW DATABASES", false);
        statement = connection->createStatement();
        resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            std::string database_name = resultSet->getString("Database");
            if (database_name == DATABASE_NAME) {
                return true;
            }
        }
    } catch (sql::SQLException &exception) {
        PrintError(exception);
    }

    return false;
}

bool DatabaseManager::is_table_exists(const std::string& table) {
    if (!is_connected_to_database) {
        connect_to_db();
    }

    try {
        SetQuery("SHOW TABLES", false);
        statement = connection->createStatement();
        resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            std::string table_name = resultSet->getString("Table");
            if (table_name == table) {
                return true;
            }
        }
    } catch (sql::SQLException &exception) {
        PrintError(exception);
    }

    return false;
}

bool DatabaseManager::create_table(const std::string& table_name,
                                   const std::vector<std::pair<std::string, std::string>>& columns) {
    if (!is_connected_to_database) {
        connect_to_db();
    }

    query = "CREATE TABLE " + table_name + "(";
    for(size_t i = 0; i < columns.size(); ++i) {
        query += columns[i].first + " " + columns[i].second;
        if (i != columns.size() - 1) {
            query += ", ";
        }
    }

    query += ");";
    std::cout << query << std::endl;
    return true;
}
