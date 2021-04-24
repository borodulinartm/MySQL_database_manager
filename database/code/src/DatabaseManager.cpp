#include "DatabaseManager.h"

bool DatabaseManager::connect_to_db() {
    std::cout << "Connected\n";
    return true;
}

bool DatabaseManager::disconnect_to_db() {
    std::cout << "Disconnected\n";
    return true;
}

bool DatabaseManager::create_db() {
    conn_ptr = mysql_init(nullptr);
    if (!conn_ptr) {
        std::cerr << "An error occured: " << mysql_error(conn_ptr) << std::endl;
        mysql_close(conn_ptr);
        return false;
    }

    if (mysql_query(conn_ptr, query.c_str())) {
        std::cerr << "An error occured: " << mysql_error(conn_ptr) << std::endl;
        mysql_close(conn_ptr);
        return false;
    }

    mysql_close(conn_ptr);
    std::cout << "SUCCESS\n";

    return true;
}

bool DatabaseManager::is_db_exists() {
    return true;
}
