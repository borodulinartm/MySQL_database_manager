#ifndef DATABASE_ITABLEMANAGER_H
#define DATABASE_ITABLEMANAGER_H

#include <string>
#include <vector>

class ITableManager {
public:
    // Методы для функций таблиц
    virtual bool add() = 0;
    virtual std::vector<std::vector<std::string>> get() = 0;
    virtual std::vector<std::vector<std::string>> get(std::vector<std::pair<std::string, std::string>> condition) = 0;
    virtual bool erase(int id) = 0;
    virtual bool update(std::vector<std::pair<std::string, std::string>> &val, std::vector<std::pair<std::string, std::string>> &columns) = 0;

};

#endif //DATABASE_ITABLEMANAGER_H
