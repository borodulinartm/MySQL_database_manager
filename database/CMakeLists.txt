cmake_minimum_required(VERSION 3.19)
project(database_prog)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-lmysqlcppconn)
include_directories(code/include)

set(LIB_SOURCE_FILES
        code/src/CafeManager.cpp code/src/ClientManager.cpp code/src/DatabaseManager.cpp
        code/src/FoodManager.cpp code/src/ListFoodManager.cpp code/src/LocationManager.cpp
        code/src/QueueManager.cpp code/src/OrderManager.cpp
        code/src/DataManager.cpp code/src/SupplierManager.cpp
)

add_library(database SHARED ${LIB_SOURCE_FILES})

set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR /usr/local/mysql/connector-c++-)

find_package(Boost COMPONENTS locale REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/mysql)
link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64)

add_executable(prog code/src/main.cpp)

target_link_libraries(prog database)
target_link_libraries(prog)
target_link_libraries(prog mysqlcppconn)
target_link_libraries(prog ${Boost_LIBRARIES})
target_compile_features(prog PRIVATE cxx_range_for)

# Тесты
enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(tests/include)

add_executable(test_database tests/src/tests.cpp tests/src/test_utils.cpp)

target_link_libraries(test_database ${GTEST_LIBRARIES} -lpthread)
target_link_libraries(test_database database)
target_link_libraries(test_database mysqlcppconn)