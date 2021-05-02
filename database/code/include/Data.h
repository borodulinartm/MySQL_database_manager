#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include <string>
#include <vector>

struct client {
    int user_id;
    std::string name;
    std::string login;
    std::string password;
    int registration_code;

    static std::vector<std::pair<std::string, std::string>> get_cols_sql();
    static std::vector<std::string> get_cols();
};

struct list_food {
    int id_products;
    int id_food;
    int count_buying;
    int total_cost;

    static std::vector<std::pair<std::string, std::string>> get_cols_sql();
    static std::vector<std::string> get_cols();
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
