#include <cstring>
#include "DatabaseManager.h"


DatabaseManager::DatabaseManager() {
    conn_ptr = mysql_init(nullptr);
    is_connected = false;
}

void DatabaseManager::set_query(const std::string& _query, bool add_database_name) {
    if (!query.empty()) {
        query.clear();
    }

    if (add_database_name) {
        query = _query + DATABASE_NAME;
    } else {
        query = _query;
    }
}

DatabaseManager::~DatabaseManager() {
    if (!conn_ptr) {
        mysql_close(conn_ptr);
    }
}

bool DatabaseManager::is_db_connected() const {
    return is_connected;
}

// Подключение к юзеру базы данных
bool DatabaseManager::connect_to_user() {
    // Если мы не проинициализировали conn_ptr
    if (!conn_ptr) {
        std::cerr << ERROR_TITLE << mysql_error(conn_ptr) << std::endl;
        return false;
    }

    // Взаимодействие происходит с пользователем, поэтому прежде чем делать запросы подключаемся
    // к юзеру
    if (mysql_real_connect(conn_ptr, "localhost", "artem", "!School211410l", nullptr,
                           0, nullptr, 0) == nullptr) {
        std::cerr << ERROR_TITLE << mysql_error(conn_ptr) << std::endl;
        is_connected = false;
        return false;
    }

    is_connected = true;
    return is_connected;
}

//================DATABASE METHODS=================

// Метод осуществляет подключение к базе данных от пользователя
bool DatabaseManager::connect_to_db() {
    if (mysql_real_connect(conn_ptr, "localhost", "artem", "!School211410l", DATABASE_NAME,
                           0, nullptr, 0) == nullptr) {
        std::cerr << ERROR_TITLE << mysql_error(conn_ptr) << std::endl;
        return false;
    }

    return true;
}

// Метод создаёт базу данных без каких-либо таблиц
bool DatabaseManager::create_db() {
    set_query("CREATE DATABASE ");

    if (!connect_to_user()) {
        std::cerr << "Can not connect to user\n";
        return false;
    }

    // Выполнение запроса
    if (mysql_query(conn_ptr, query.c_str())) {
        std::cerr << "An error occured: " << mysql_error(conn_ptr) << std::endl;
        return false;
    }

    return true;
}

bool DatabaseManager::is_db_exists() {
    set_query("SHOW DATABASES", false);

    if (mysql_query(conn_ptr, query.c_str())) {
        std::cerr << ERROR_TITLE << mysql_error(conn_ptr) << std::endl;
        return false;
    }

    MYSQL_RES *data_result = mysql_store_result(conn_ptr);
    if (data_result == nullptr) {
        std::cout << "No data\n";
        return false;
    }

    int num_fields = static_cast<int>(mysql_num_fields(data_result));
    MYSQL_ROW current_row;

    while ((current_row = mysql_fetch_row(data_result))) {
        for(size_t i = 0; i < num_fields; ++i) {
            if (current_row[i] != nullptr && strcmp(current_row[i], DATABASE_NAME) == 0) {
                mysql_free_result(data_result);
                return true;
            }
        }
    }

    mysql_free_result(data_result);
    return false;
}

