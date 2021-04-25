#ifndef UNTITLED_MY_INTERFACE_H
#define UNTITLED_MY_INTERFACE_H

#include <string>
#include <mysql_connection.h>
#include "Data.h"

// Центральный интерфейс для работы с БД
class IDatabaseManager {
protected:
    // Методы для БД
    virtual bool connect_to_db() = 0;
    virtual bool create_db() = 0;
    virtual bool is_db_exists() = 0;
};

#endif //UNTITLED_MY_INTERFACE_H
