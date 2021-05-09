#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>

#include "TableManager.h"
#include "test_utils.h"

// Тестирование создания таблицы
TEST(create_table, create_table) {
    // Делаем на примере с клиентами
    ClientManager clientManager;
    client c;
    std::string table_name = "clients";

    std::vector<std::pair<std::string, std::string>> cols_sql = c.get_cols_sql();

    DatabaseManager dbManager = clientManager.get_database_manager();
    dbManager.create_table(table_name, cols_sql);

    std::string query = "SHOW TABLES";
    std::vector<std::string> tables = execute_query(query);

    if (tables.empty()) {
        FAIL() << "Error in fetching result";
    }

    bool is_found = false;
    for(auto &table: tables) {
        std::cout << table << " ";
        if (table_name == table) {
            is_found = true;
        }
    }

    if (is_found) {
        SUCCEED();
    } else {
        FAIL() << "table not found";
    }
}

// Тестирование вставки данных
TEST(insert_data, insert) {
    std::vector<client> my_client = get_client();
    ClientManager clientManager;

    for(auto &client: my_client) {
        clientManager.add(client);
    }

    auto cols = my_client[0].get_cols();
    std::string query = "SELECT * FROM clients";
    auto result = get_from_client(query, cols);

    if (my_client.size() != result.size()) {
        FAIL() << "Sizes are not equal";
    }

    for(size_t i = 0; i < result.size(); ++i) {
        if (!is_equal(my_client[i], result[i])) {
            FAIL() << "Data not equal";
        }
    }

    SUCCEED();
}

// Тестирование извлечения данных (когда извлекаем все данные целиком)
TEST(get_data, get) {
    std::vector<client> my_client = get_client();
    ClientManager clientManager;
    bool is_good = false;

    auto result = clientManager.get();

    for(auto &client: my_client) {
        for (auto &i : result) {
            if (is_equal(client, i)) {
                is_good = true;
            }
        }
    }

    if (!is_good) {
        FAIL() << "Data not equal";
    }

    SUCCEED();
}

// Тестирование извлечения данных по определённому критерию
TEST(get_data_condition, get_condition) {
    std::string name = "Artem";
    std::vector<client> my_client = get_client();
    auto filtered_by_name = get_filtered_clients(my_client, name);

    ClientManager clientManager;

    std::vector<std::pair<std::string, std::string>> condition;
    condition.emplace_back("name", "Artem");
    auto result = clientManager.get(condition);

    if (result.size() != filtered_by_name.size()) {
        FAIL() << "Sizes are not equal";
    }

    for(size_t i = 0; i < result.size(); ++i) {
        if (!is_equal(filtered_by_name[i], result[i])) {
            FAIL() << "Data are not equal";
        }
    }

    SUCCEED();
}

// Тестирование обновления данных
TEST(update_value, update_test) {
    std::string new_name = "!!!Artem";
    ClientManager clientManager;

    std::vector<std::pair<std::string, std::string>> updated_data;
    updated_data.emplace_back("name", new_name);

    std::vector<std::pair<std::string, std::string>> condition;
    condition.emplace_back("name", "Artem");

    clientManager.update(updated_data, condition);

    std::vector<client> my_client = get_client();
    auto filtered_data = get_filtered_clients(my_client, new_name);

    for(auto & i : filtered_data) {
        if (i.peopleInfo.name != new_name) {
            FAIL() << "Data not updated";
        }
    }

    SUCCEED();
}

// Тестирование удаления данных из БД
TEST(delete_value, remove) {
    ClientManager clientManager;
    std::vector<std::vector<std::string>> result = clientManager.get();

    for(auto & i : result) {
        // Очищаем БД
        clientManager.erase(std::stoi(i[0]));
    }

    if (clientManager.get().empty()) {
        SUCCEED();
    } else {
        FAIL() << "Data has not destroyed";
    }
}

// Тестирование конвертации данных (когда мы переводим из структуры)
// в удобный для БД вид
TEST(convert_to_vector, convert) {
    std::vector<client> my_client = get_client();
    ClientManager clientManager;

    for(auto &client: my_client) {
        clientManager.set_client(client);
        std::vector<std::string> converted_string = clientManager.to_vector();

        if (!is_equal(client, converted_string)) {
            FAIL() << "Error in converting data";
        }
    }

    SUCCEED();
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}