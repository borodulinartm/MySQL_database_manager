cmake_minimum_required(VERSION 3.19)
project(database_prog)

set(CMAKE_CXX_STANDARD 14)
include_directories(code/include)

set(LIB_SOURCE_FILES
        code/src/CafeManager.cpp code/src/ClientManager.cpp code/src/DatabaseManager.cpp
        code/src/FoodManager.cpp code/src/ListFoodManager.cpp code/src/LocationManager.cpp
        code/src/QueueManager.cpp code/src/OrderManager.cpp
)

add_library(database STATIC ${LIB_SOURCE_FILES})

add_executable(database_prog code/src/main.cpp)
target_link_libraries(database_prog database)

# Тесты
enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(tests/include)

add_executable(test_database tests/src/tests.cpp tests/src/test_utils.cpp)

target_link_libraries(test_database ${GTEST_LIBRARIES} -lpthread)
target_link_libraries(test_database database)
