#include "mysql_driver.h"
#include <mysql_connection.h>
#include <cppconn/driver.h>

using namespace std;


int main(){
    auto driver = sql::mysql::get_driver_instance();
    return 0;
}