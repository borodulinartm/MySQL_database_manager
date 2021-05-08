#include "test_utils.h"

std::vector<std::vector<std::string>> get_from_client(std::string &query, std::vector<std::string> &cols) {
    std::vector<std::vector<std::string>> to_return;

    try {
        sql::Driver *driver = sql::mysql::get_driver_instance();
        sql::Connection *connection = driver->connect("localhost", "artem", "!School211410l");

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
        std::cout << "You're loser\n";
    }

    return to_return;
}

client get_client() {
    std::ifstream stream("../tests/data/1.tst");
    if (!stream.is_open()) {
        std::string message = "OOPS\n";
        throw std::runtime_error(message.c_str());
    }

    client my_client;
    stream >> my_client.user_id >> my_client.peopleInfo.name >>
           my_client.peopleInfo.login >> my_client.peopleInfo.password >>
           my_client.peopleInfo.registration_code;
    
    stream.close();

    return my_client;
}
