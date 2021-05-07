#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include <string>
#include <vector>

#include "IData.h"

//! Конструкторы надо определять с инициализацией данных

struct people_info {
    std::string name;
    std::string login;
    std::string password;
    int registration_code;
};

struct client: public wrapper {
    int user_id;
    people_info peopleInfo;

    client(int _user_id, std::string _name, std::string _login, std::string _password, int _code);
    client();

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

struct supplier: public wrapper {
    int supplier_id;
    int cafe_id;
    people_info peopleInfo;

    supplier(int _supplier_id, int _cafe_id,
             std::string _name, std::string _login, std::string _password, int _code);
    supplier();

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

struct list_food: public wrapper {
    int id_products;
    int id_food;
    int count_buying;
    int total_cost;

    list_food(int _id_products, int _id_food, int _count_buying, int _total_cost);
    list_food();

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

struct location: public wrapper {
    int id_location;
    std::string type_building;
    int floor;

    location(int _id_location, std::string _type_building, int _floor);
    location();

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

struct cafe: public wrapper {
    int id_cafe;
    int id_location;
    int id_food;
    int count_food;

    cafe(int _id_cafe, int _id_location, int _id_food, int _count_food);
    cafe();

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

struct order: public wrapper {
    int id_order;
    int id_cafe;
    int id_user;
    int id_products;
    int id_slot;
    int total_cost;
    int stage;
    int id_supplier;

    order(int _id_order, int _id_cafe, int _id_user, int _id_products, int _id_slot, int _total_cost,
          int _stage, int _id_supplier);
    order();

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

struct food: public wrapper {
    int id_food;
    std::string name_eat;
    int cost;
    int where_use;

    food(int _id_food, std::string _name_eat, int _cost, int _where_use);
    food();

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

struct queue: public wrapper {
    int id_slot;
    int hour;
    int minute;

    queue(int _id_slot, int _hour, int _minute);
    queue();

    std::vector<std::pair<std::string, std::string>> get_cols_sql() override;
    std::vector<std::string> get_cols() override;
};

#endif //UNTITLED_DATA_H
