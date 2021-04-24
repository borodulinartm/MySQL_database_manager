#ifndef DATABASE_ITABLEMANAGER_H
#define DATABASE_ITABLEMANAGER_H

#include <string>

class ITableManager {
public:
    // Методы для функций таблиц
    virtual bool add(std::string data) = 0;
    virtual std::string get(int id) = 0;
    virtual bool erase(int id) = 0;
    virtual void from_string(std::string string) = 0;
    virtual std::string to_string() = 0;
};

#endif //DATABASE_ITABLEMANAGER_H
