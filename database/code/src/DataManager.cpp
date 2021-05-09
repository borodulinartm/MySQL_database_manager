#include <utility>

#include "Data.h"

// Таблица "Клиенты"
// Даный метод возвращает все столбцы данной таблицы
std::vector<std::pair<std::string, std::string>> client::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;

    cols.emplace_back("id", "INT AUTO_INCREMENT");
    cols.emplace_back("PRIMARY KEY", "(id)");
    cols.emplace_back("name", "VARCHAR(30)");
    cols.emplace_back("login", "VARCHAR(50)");
    cols.emplace_back("password", "VARCHAR(30)");
    cols.emplace_back("registration_code", "INT");

    return cols;
}

std::vector <std::string> client::get_cols() {
    std::vector<std::string> cols = {"id", "name", "login", "password", "registration_code"};
    return cols;
}

client::client(int _user_id, std::string _name, std::string _login, std::string _password, int _code):
        user_id(_user_id) {
    peopleInfo.name = std::move(_name);
    peopleInfo.login = std::move(_login);
    peopleInfo.password = std::move(_password);
    peopleInfo.registration_code = _code;
}

client::client(): user_id(0) {
    peopleInfo.name = "";
    peopleInfo.login = "";
    peopleInfo.password = "";
    peopleInfo.registration_code = 0;
}

// Таблица "Продавцы"

std::vector<std::string> supplier::get_cols() {
    std::vector<std::string> cols = {"id", "cafe_id", "name", "login", "password", "registration_code"};
    return cols;
}

std::vector<std::pair<std::string, std::string>> supplier::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;

    cols.emplace_back("id", "INT AUTO_INCREMENT");
    cols.emplace_back("PRIMARY KEY", "(id)");
    cols.emplace_back("cafe_id", "INT");
    cols.emplace_back("name", "VARCHAR(30)");
    cols.emplace_back("login", "VARCHAR(50)");
    cols.emplace_back("password", "VARCHAR(30)");
    cols.emplace_back("registration_code", "INT");

    return cols;
}

supplier::supplier(int _supplier_id, int _cafe_id, std::string _name, std::string _login, std::string _password,
                   int _code): supplier_id(_supplier_id), cafe_id(_cafe_id) {
    peopleInfo.name = std::move(_name);
    peopleInfo.login = std::move(_login);
    peopleInfo.password = std::move(_password);
    peopleInfo.registration_code = _code;
}

supplier::supplier(): supplier_id(0), cafe_id(0) {
    peopleInfo.name = "";
    peopleInfo.login = "";
    peopleInfo.password = "";
    peopleInfo.registration_code = 0;
}

// Таблица "Список еды"

std::vector<std::pair<std::string, std::string>> list_food::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;
    cols.emplace_back("id", "INT AUTO_INCREMENT");
    cols.emplace_back("PRIMARY KEY", "(id)");
    cols.emplace_back("id_food", "INT");
    cols.emplace_back("count_buying", "INT");
    cols.emplace_back("total_cost", "INT");

    return cols;
}

std::vector<std::string> list_food::get_cols() {
    std::vector<std::string> cols = {"id", "id_food", "count_buying", "total_cost"};
    return cols;
}

list_food::list_food(int _id_products, int _id_food, int _count_buying, int _total_cost):
    id_products(_id_products), id_food(_id_food), count_buying(_count_buying), total_cost(_total_cost) {
}

list_food::list_food(): id_products(0), id_food(0), count_buying(0), total_cost(0) {
}

// Таблица "Местоположение"

location::location(int _id_location, std::string _type_building, int _floor):
        id_location(_id_location), type_building(std::move(_type_building)), floor(_floor) {
}

std::vector<std::pair<std::string, std::string>> location::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;
    cols.emplace_back("id", "INT AUTO_INCREMENT");
    cols.emplace_back("PRIMARY KEY", "(id)");
    cols.emplace_back("type_building", "VARCHAR(30)");
    cols.emplace_back("floor", "INT");

    return cols;
}

std::vector<std::string> location::get_cols() {
    std::vector<std::string> cols = {"id", "type_building", "floor"};
    return cols;
}

location::location(): id_location(0), type_building(""), floor(0) {
}

// Таблица "Кафе"

cafe::cafe(int _id_cafe, int _id_location, int _id_food, int _count_food):
    id_cafe(_id_cafe), id_location(_id_location), id_food(_id_food), count_food(_count_food) {
}

std::vector<std::pair<std::string, std::string>> cafe::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;
    cols.emplace_back("id", "INT AUTO_INCREMENT");
    cols.emplace_back("PRIMARY KEY", "(id)");
    cols.emplace_back("id_location", "INT");
    cols.emplace_back("id_food", "INT");
    cols.emplace_back("count_food", "INT");

    return cols;
}

std::vector<std::string> cafe::get_cols() {
    std::vector<std::string> cols = {"id", "id_location", "id_food", "count_food"};
    return cols;
}

cafe::cafe(): id_cafe(0), id_location(0), id_food(0), count_food(0) {
}

// Таблица "Заказ"

order::order(int _id_order, int _id_cafe, int _id_user, int _id_products, int _id_slot, int _total_cost, int _stage,
             int _id_supplier): id_order(_id_order), id_cafe(_id_cafe), id_user(_id_user), id_products(_id_products),
             id_slot(_id_slot), total_cost(_total_cost), stage(_stage), id_supplier(_id_supplier) {
}

std::vector<std::string> order::get_cols() {
    std::vector<std::string> cols = {"id", "id_cafe", "id_user", "id_products",
                                     "id_slot", "total_cost", "stage", "id_supplier"};
    return cols;
}

std::vector<std::pair<std::string, std::string>> order::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;
    cols.emplace_back("id", "INT AUTO_INCREMENT");
    cols.emplace_back("PRIMARY KEY", "(id)");
    cols.emplace_back("id_cafe", "INT");
    cols.emplace_back("id_user", "INT");
    cols.emplace_back("id_products", "INT");
    cols.emplace_back("id_slot", "INT");
    cols.emplace_back("total_cost", "INT");
    cols.emplace_back("stage", "INT");
    cols.emplace_back("id_supplier", "INT");

    return cols;
}

order::order(): id_order(0), id_cafe(0), id_user(0), id_products(0), id_slot(0), total_cost(0), stage(0), id_supplier(0) {
}

// Таблица "Еда"
food::food(int _id_food, std::string _name_eat, int _cost, int _where_use):
    id_food(_id_food), name_eat(std::move(_name_eat)), cost(_cost), where_use(_where_use) {
}

std::vector<std::pair<std::string, std::string>> food::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;
    cols.emplace_back("id", "INT AUTO_INCREMENT");
    cols.emplace_back("PRIMARY KEY", "(id)");
    cols.emplace_back("name_eat", "VARCHAR(30)");
    cols.emplace_back("cost", "INT");
    cols.emplace_back("where_use", "INT");

    return cols;
}

std::vector<std::string> food::get_cols() {
    std::vector<std::string> cols = {"id", "name_eat", "cost", "where_use"};
    return cols;
}

food::food(): id_food(0), name_eat(""), where_use(0) {
}

// Таблица "Очередь"

queue::queue(int _id_slot, int _hour, int _minute): id_slot(_id_slot), hour(_hour), minute(_minute) {
}

std::vector<std::pair<std::string, std::string>> queue::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;
    cols.emplace_back("id", "INT AUTO_INCREMENT");
    cols.emplace_back("PRIMARY KEY", "(id)");
    cols.emplace_back("hour", "INT");
    cols.emplace_back("minute", "INT");

    return cols;
}

std::vector<std::string> queue::get_cols() {
    std::vector<std::string> cols = {"id", "hour", "minute"};
    return cols;
}

queue::queue(): id_slot(0), hour(0), minute(0) {
}

std::string get_from_enum(int type) {
    std::string result;
    switch (type) {
        case TYPE_BUILDING::GZ:
            result = "ГЗ";
            break;

        case TYPE_BUILDING::SK:
            result = "СК";
            break;

        case TYPE_BUILDING::ULK:
            result = "УЛК";
            break;

        default:
            result = "";
            break;
    }

    return result;
}