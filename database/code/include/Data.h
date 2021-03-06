#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include <string>

struct client {
    int user_id;
    std::string name;
    std::string login;
    std::string password;
    int registration_code;
    int id_dislike_food;
};

struct list_food {
    int id_products;
    int id_food;
    int count_buying;
    int total_cost;
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
