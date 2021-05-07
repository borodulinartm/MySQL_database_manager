#include "TableManager.h"

/*
    * Логика будет описана в дальнейшем
*/

CafeManager::CafeManager(const DatabaseManager& _dbManager, cafe _my_cafe):
    table_name("cafe"), dbManager(_dbManager), my_cafe(_my_cafe) {
}

CafeManager::CafeManager(cafe _my_cafe): table_name("clients"), my_cafe(_my_cafe) {
}

bool CafeManager::add(std::string data) {
    return false;
}

bool CafeManager::erase(int id) {
    return false;
}

cafe CafeManager::get_cafe() const {
    return my_cafe;
}

std::vector<std::vector<std::string>> CafeManager::get(int id) {
    return std::vector<std::vector<std::string>>();
}
