#include <utility>

#include "Data.h"

// Таблица "Клиенты"
// Даный метод возвращает все столбцы данной таблицы
std::vector<std::pair<std::string, std::string>> client::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;

    cols.emplace_back("id", "INT");
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

// Таблица "Продавцы"

std::vector<std::string> supplier::get_cols() {
    std::vector<std::string> cols = {"id", "cafe_id", "name", "login", "password", "registration_code"};
    return cols;
}

std::vector<std::pair<std::string, std::string>> supplier::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;

    cols.emplace_back("id", "INT");
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

// Таблица "Список еды"

std::vector<std::pair<std::string, std::string>> list_food::get_cols_sql() {
    std::vector<std::pair<std::string, std::string>> cols;
    cols.emplace_back("id", "INT");
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
