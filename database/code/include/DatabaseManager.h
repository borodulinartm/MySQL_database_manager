#ifndef UNTITLED_DB_MANAGER_H
#define UNTITLED_DB_MANAGER_H

#include "IDatabaseManager.h"
#include "Data.h"

#include <mysql_driver.h>
#include <cppconn/driver.h>

#include <iostream>

#define ADDRESS "localhost"
#define USER_NAME "artem"
#define PASSWORD "!School211410l"


class DatabaseManager: public IDatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();

    bool connect_to_db() override;
    bool disconnect_to_db() override;
    bool create_db() override;
    bool is_db_exists() override;

    bool _connectToUser();
    bool _disconnectToUser();

private:
    sql::Driver *driver;

    sql::Connection *connection;
    bool is_connected_to_user;
};

#endif //  UNTITLED_DB_MANAGER_H
