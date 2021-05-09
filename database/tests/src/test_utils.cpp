#include "test_utils.h"

std::vector<std::vector<std::string>> get_from_client(std::string &query, std::vector<std::string> &cols) {
    std::vector<std::vector<std::string>> to_return;

    try {
        sql::Driver *driver = sql::mysql::get_driver_instance();
        sql::Connection *connection = driver->connect("localhost", "artem", "!School211410l");
        connection->setSchema("testdb");

        sql::Statement *statement = connection->createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        std::vector<std::string> row;
        while (resultSet->next()) {
            for(auto &col: cols) {
                row.push_back(resultSet->getString(col));
            }

            to_return.push_back(row);
            row.clear();
        }

    } catch (sql::SQLException &exception) {
        std::cout << exception.what();
    }

    return to_return;
}

std::vector<client> get_client() {
    std::ifstream stream("../tests/data/1.tst");
    if (!stream.is_open()) {
        std::cerr << "OOPS";
    }

    std::vector<client> to_return;
    client my_client;

    while (!stream.eof()) {
        stream >> my_client.user_id >> my_client.peopleInfo.name >>
               my_client.peopleInfo.login >> my_client.peopleInfo.password >>
               my_client.peopleInfo.registration_code;
        to_return.push_back(my_client);
    }

    stream.close();
    return to_return;
}

bool is_equal(const client& my_client, std::vector<std::string> data) {
    std::string code = std::to_string(my_client.peopleInfo.registration_code);
    if (my_client.peopleInfo.name == data[1] && my_client.peopleInfo.login == data[2] &&
            my_client.peopleInfo.password == data[3] && code == data[4]) {
        return true;
    }

    return false;
}
