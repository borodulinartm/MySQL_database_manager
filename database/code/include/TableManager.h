#ifndef DATABASE_TABLEMANAGER_H
#define DATABASE_TABLEMANAGER_H

#include "ITableManager.h"
#include "Data.h"
#include "DatabaseManager.h"

#include <vector>

class ClientManager: public ITableManager {
private:
    DatabaseManager dbManager;
    std::string table_name;
    client my_client;

public:
    ClientManager(const DatabaseManager& _dbManager, client _my_client);
    explicit ClientManager(client _my_client);

    // Переопределённые методы
    bool add(std::string data) override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;

    std::vector<std::string> to_vector();
};

class CafeManager: public DatabaseManager, ITableManager {
private:
    cafe my_cafe;
public:
    CafeManager();
    explicit CafeManager(cafe _my_cafe);

    // Геттер
    cafe get_cafe() const;

    // Переопределённые методы
    bool add(std::string data) override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
};

class QueueManager: public DatabaseManager, ITableManager {
private:
    queue my_queue;
public:
    QueueManager();
    explicit QueueManager(queue _my_queue);

    // Геттер
    queue get_queue() const;

    // Переопределённые методы
    bool add(std::string data) override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
};

class ListFoodManager: public DatabaseManager, ITableManager {
private:
    std::vector<list_food> my_list_food;
public:
    ListFoodManager();
    explicit ListFoodManager(std::vector<list_food> _my_list_food);

    // Геттер
    std::vector<list_food> get_list_food();

    // Переопределённые методы
    bool add(std::string data) override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
};

class FoodManager: public DatabaseManager, ITableManager {
private:
    food my_food;
public:
    FoodManager();
    explicit FoodManager(food my_food);

    // Геттер
    food get_food() const;

    // Переопределённые методы
    bool add(std::string data) override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
};

class OrderManager: public DatabaseManager, ITableManager {
private:
    order my_order;
public:
    OrderManager();
    explicit OrderManager(order _my_order);

    // Геттер
    order get_order() const;

    // Переопределённые методы
    bool add(std::string data) override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
};

class LocationManager: public DatabaseManager, ITableManager {
private:
    location my_location;
public:
    LocationManager();
    explicit LocationManager(location _my_location);

    // Геттер
    location get_location() const;

    // Переопределённые методы
    bool add(std::string data) override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
};

#endif //  DATABASE_TABLEMANAGER_H
