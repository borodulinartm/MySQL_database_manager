#include <gtest/gtest.h>
#include <iostream>
#include <fstream>

#include "TableManager.h"
#include "test_utils.h"

TEST(insert_data, insert) {
    client my_client = get_client();
    ClientManager clManager(my_client);
    std::cout << my_client.user_id << " " << my_client.peopleInfo.name << std::endl;
    clManager.add();
}

TEST(get_data, get) {
    SUCCEED();
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}