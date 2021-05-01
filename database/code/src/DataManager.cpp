#include "Data.h"

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
