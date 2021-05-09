#ifndef DATABASE_PROG_TEST_UTILS_H
#define DATABASE_PROG_TEST_UTILS_H

#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

#include "TableManager.h"

sql::Connection *connect();
std::vector<std::vector<std::string>> get_from_client(std::string &query, std::vector<std::string> &cols);
std::vector<client> get_client();
bool is_equal(const client& my_client, std::vector<std::string> data);
std::vector<client> get_filtered_clients(std::vector<client> list_clients, std::string &filter);
std::vector<std::string> execute_query(const std::string &query);

#endif //DATABASE_PROG_TEST_UTILS_H
