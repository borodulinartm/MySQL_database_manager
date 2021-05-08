#include <gtest/gtest.h>
#include <iostream>

#include "TableManager.h"
#include "test_utils.h"

TEST(insert_data, insert) {
    client my_client = get_client();
    ClientManager clientManager(my_client);
    clientManager.add();
}

TEST(get_data, get) {
    client my_client = get_client();

    ClientManager clientManager(my_client);
    bool is_good = false;
    auto result = clientManager.get();

    for (auto &i : result) {
        if (is_equal(my_client, i)) {
            is_good = true;
        }
    }

    if (!is_good) {
        FAIL() << "ERROR!!!";
    }
}

TEST(delete_value, remove) {

}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}