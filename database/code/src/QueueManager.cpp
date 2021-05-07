#include <utility>

#include "TableManager.h"

QueueManager::QueueManager(const DatabaseManager& _dbManager, queue _my_queue):
    table_name("queue"), dbManager(_dbManager), my_queue(std::move(_my_queue)){
}

QueueManager::QueueManager(queue _my_queue): table_name("queue"),
    my_queue(std::move(_my_queue)) {
}

bool QueueManager::add(std::string data) {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }

    if (!dbManager.is_table_exists(table_name)) {
        std::cout << "TABLE NOT EXIST\n";
        auto cols = my_queue.get_cols_sql();
        dbManager.create_table(table_name, cols);
    }

    auto res = to_vector();
    dbManager.insert_data(table_name, res);

    return true;
}

bool QueueManager::erase(int id) {
    return dbManager.delete_data(table_name, id);
}

queue QueueManager::get_queue() const {
    return my_queue;
}

std::vector<std::vector<std::string>> QueueManager::get(int id) {
    std::vector<std::vector<std::string>> to_return = dbManager.get_data(
            table_name, my_queue.get_cols()
    );

    return to_return;
}

std::vector<std::string> QueueManager::to_vector() {
    std::vector<std::string> to_return = {
            std::to_string(my_queue.id_slot),
            std::to_string(my_queue.hour),
            std::to_string(my_queue.minute)
    };

    return to_return;
}

bool QueueManager::update(int id, std::vector<std::pair<std::string, std::string>> &val) {
    if (!dbManager.is_db_exists()) {
        dbManager.create_db();
    }

    if (!dbManager.is_connected_to_db()) {
        dbManager.connect_to_db();
    }

    return dbManager.update_data(table_name, val, id);
}
