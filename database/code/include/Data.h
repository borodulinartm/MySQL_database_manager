#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include <string>
#include <vector>

#include "IData.h"

struct people_info {
    std::string name;
    std::string login;
    std::string password;
    int registration_code;
};

struct client: public wrapper {
    int user_id = 0;
    people_info peopleInfo;

    client(int _user_id, std::string _name, std::string _login, std::string _password, int _code);
    client() = default;

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

struct supplier: public wrapper {
    int supplier_id = 0;
    int cafe_id = 0;
    people_info peopleInfo;

    supplier(int _supplier_id, int _cafe_id,
             std::string _name, std::string _login, std::string _password, int _code);
    supplier() = default;

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

struct list_food: public wrapper {
    int id_products = 0;
    int id_food = 0;
    int count_buying = 0;
    int total_cost = 0;

    list_food(int _id_products, int _id_food, int _count_buying, int _total_cost);
    list_food() = default;

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

struct order {
    int id_order;
    int id_cafe;
    int id_user;
    int id_products;
    int id_slot;
    int total_cost;
    int stage;
    int id_supplier;
};

struct cafe {
    int id_cafe;
    int id_location;
    int id_food;
    int count_food;
};

struct food {
    int id_food;
    std::string name_eat;
    int cost;
    int where_use;
};

struct location {
    int id_location;
    std::string type_building;
    int floor;
};

struct queue {
    int id_slot;
    int hour;
    int minute;
};

#endif //UNTITLED_DATA_H
