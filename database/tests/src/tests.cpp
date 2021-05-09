#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>

#include "TableManager.h"
#include "test_utils.h"

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
    std::vector<client> my_client = get_client();
    std::vector<client> filtered_by_name (my_client.size());

    auto it = std::copy_if(my_client.begin(), my_client.end(), filtered_by_name.begin(),
                           [](const client& curr_client) {
        return curr_client.peopleInfo.name == "Artem";
    });

    filtered_by_name.resize(std::distance(filtered_by_name.begin(), it));

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

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}