#include "test_utils.h"

sql::Connection *connect() {
    try {
        sql::Driver *driver = sql::mysql::get_driver_instance();
        sql::Connection *connection = driver->connect("localhost", "artem", "!School211410l");
        return connection;
    } catch (sql::SQLException &exception) {
        std::cerr << exception.what();
    }

    return nullptr;
}

std::vector<std::vector<std::string>> get_from_client(std::string &query, std::vector<std::string> &cols) {
    std::vector<std::vector<std::string>> to_return;

    try {
        auto connection = connect();
        if (connection == nullptr) {
            std::cerr << "Error in connecting";
            return to_return;
        }

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

std::vector<std::string> execute_query(const std::string &query, const std::string& col) {
    std::vector<std::string> to_return;

    try {
        auto connection = connect();
        if (connection == nullptr) {
            std::cerr << "Error in connecting";
            return to_return;
        }

        connection->setSchema("testdb");
        sql::Statement *statement = connection->createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            to_return.push_back(resultSet->getString(col));
        }

        return to_return;
    } catch (sql::SQLException &exception) {
        std::cerr << exception.what() << std::endl;
    }

    return to_return;
}

std::vector<client> get_client() {
    std::ifstream stream("../tests/data/1.tst");
    if (!stream.is_open()) {
        std::cerr << "OOPS";
        exit(1);
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

std::vector<client> get_filtered_clients(std::vector<client> list_clients, std::string &filter) {
    std::vector<client> filtered_by_name (list_clients.size());

    auto it = std::copy_if(list_clients.begin(), list_clients.end(), filtered_by_name.begin(),
   [filter](const client& curr_client) {
       return curr_client.peopleInfo.name == filter;
   });

    filtered_by_name.resize(std::distance(filtered_by_name.begin(), it));
    return filtered_by_name;
}

std::vector<data> get_data() {
    std::vector<data> my_data;

    std::ifstream stream("../tests/data/2.tst");
    if (!stream.is_open()) {
        std::cerr << "OOPS";
        exit(1);
    }

    std::string text, type_data;
    data curr_data = {"", false};

    while (!stream.eof()) {
        stream >> text >> type_data;
        curr_data.text = text;

        if (type_data == "YES") {
            curr_data.is_digit = true;
        } else {
            curr_data.is_digit = false;
        }

        my_data.push_back(curr_data);
    }
    stream.close();

    return my_data;
}
