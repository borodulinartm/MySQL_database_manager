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

    void check_access();
public:
    ClientManager(const DatabaseManager& _dbManager, client _my_client);
    explicit ClientManager(client _my_client);

    // Геттер
    client get_client() const;
    DatabaseManager get_database_manager() const;
    bool add(client _client);

    // Переопределённые методы
    bool add() override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
    bool update(int id, std::vector<std::pair<std::string, std::string>> &val) override;

    std::vector<std::string> to_vector();
};

class SupplierManager: public ITableManager {
private:
    DatabaseManager dbManager;
    std::string table_name;
    supplier my_supplier;

    void check_access();
public:
    SupplierManager(const DatabaseManager& _dbManager, supplier _my_supplier);
    explicit SupplierManager(supplier _my_supplier);

    // Геттеры
    supplier get_supplier() const;
    DatabaseManager get_database_manager() const;
    bool add(supplier _supplier);

    // Переопределённые методы
    bool add() override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;

    bool update(int id, std::vector<std::pair<std::string, std::string>> &val) override;
    std::vector<std::string> to_vector();
};

class CafeManager: public DatabaseManager, ITableManager {
private:
    cafe my_cafe;
    std::string table_name;
    DatabaseManager dbManager;

    void check_access();
public:
    CafeManager(const DatabaseManager& _dbManager, cafe _my_cafe);
    explicit CafeManager(cafe _my_cafe);

    // Геттер
    cafe get_cafe() const;
    DatabaseManager get_database_manager() const;
    bool add(cafe _cafe);

    // Переопределённые методы
    bool add() override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
    bool update(int id, std::vector<std::pair<std::string, std::string>> &val) override;

    std::vector<std::string> to_vector();
};

class LocationManager: public DatabaseManager, ITableManager {
private:
    location my_location;
    std::string table_name;
    DatabaseManager dbManager;

    void check_access();
public:
    LocationManager(const DatabaseManager& _dbManager, location _my_location);
    explicit LocationManager(location _my_location);

    // Геттер
    location get_location() const;
    DatabaseManager get_database_manager() const;
    bool add(location _location);

    // Переопределённые методы
    bool add() override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
    bool update(int id, std::vector<std::pair<std::string, std::string>> &val) override;

    std::vector<std::string> to_vector();
};

class QueueManager: public DatabaseManager, ITableManager {
private:
    queue my_queue;
    std::string table_name;
    DatabaseManager dbManager;

    void check_access();
public:
    QueueManager(const DatabaseManager& _dbManager, queue _my_queue);
    explicit QueueManager(queue _my_queue);

    // Геттер
    queue get_queue() const;
    DatabaseManager get_database_manager() const;
    bool add(queue _queue);

    // Переопределённые методы
    bool add() override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
    bool update(int id, std::vector<std::pair<std::string, std::string>> &val) override;

    std::vector<std::string> to_vector();
};

class ListFoodManager: public DatabaseManager, ITableManager {
private:
    list_food my_list_food;
    DatabaseManager dbManager;
    std::string table_name;

    void check_access();
public:
    ListFoodManager(const DatabaseManager& _dbManager, list_food _my_list_food);
    explicit ListFoodManager(list_food _my_list_food);

    // Геттер
    list_food get_list_food();
    DatabaseManager get_database_manager() const;
    bool add(list_food _list_food);

    // Переопределённые методы
    bool add() override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
    bool update(int id, std::vector<std::pair<std::string, std::string>> &val) override;

    std::vector<std::string> to_vector();
};

class FoodManager: public DatabaseManager, ITableManager {
private:
    food my_food;
    DatabaseManager dbManager;
    std::string table_name;

    void check_access();
public:
    FoodManager(const DatabaseManager& _dbManager, food _my_food);
    explicit FoodManager(food _my_food);

    // Геттер
    food get_food() const;
    DatabaseManager get_database_manager() const;
    bool add(food _my_food);

    // Переопределённые методы
    bool add() override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
    bool update(int id, std::vector<std::pair<std::string, std::string>> &val) override;

    std::vector<std::string> to_vector();
};

class OrderManager: public DatabaseManager, ITableManager {
private:
    order my_order;
    DatabaseManager dbManager;
    std::string table_name;

    void check_access();
public:
    OrderManager(const DatabaseManager& _dbManager, order _my_order);
    explicit OrderManager(order _my_order);

    // Геттер
    order get_order() const;
    DatabaseManager get_database_manager() const;
    bool add(order _order);

    // Переопределённые методы
    bool add() override;
    std::vector<std::vector<std::string>> get(int id) override;
    bool erase(int id) override;
    bool update(int id, std::vector<std::pair<std::string, std::string>> &val) override;

    std::vector<std::string> to_vector();
};

#endif //  DATABASE_TABLEMANAGER_H
