#include <gtest/gtest.h>
#include <iostream>

// Тестирование конвертирование данных
TEST(test_converting_to_string_data, convert_data) {
    SUCCEED();
}

// Тест деконвертирования данных
TEST(test_deconverting_data, deconvert_data) {
    SUCCEED();
}

/* Тестирование функций БД */

// Добавление информации в БД
TEST(add_info_to_db, add_info) {
    SUCCEED();
}

TEST(get_info_from_db, get_info) {
    SUCCEED();
}

TEST(delete_info_from_db, delete_info) {
    SUCCEED();
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}