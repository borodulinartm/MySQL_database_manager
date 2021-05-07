#ifndef DATABASE_ITABLEMANAGER_H
#define DATABASE_ITABLEMANAGER_H

#include <string>
#include <vector>

class ITableManager {
public:
    // Методы для функций таблиц
    virtual bool add(std::string data) = 0;
    virtual std::vector<std::vector<std::string>> get(int id) = 0;
    virtual bool erase(int id) = 0;
    virtual bool update(int id, std::vector<std::pair<std::string, std::string>> &val) = 0;
};

#endif //DATABASE_ITABLEMANAGER_H
