#include <iostream>
#include "DatabaseManager.h"
#include "TableManager.h"
#include "Data.h"

#include <boost/locale.hpp>
#include <ctime>
#define PRINTER(name) printer(#name)

std::string printer(const char *name) {
    std::string v(name);
    return v;
}

int main() {
    DatabaseManager databaseManager;
    supplier cl(1,2, "Vasya", "@bus", "dedf", 2);
    order o(0,2,3,4,5,6,7,8);

    SupplierManager supplierManager(cl);
    OrderManager orderManager(o);

    supplierManager.add();
    orderManager.add();

    auto big_data = supplierManager.get();
    auto big_data_2 = orderManager.get();
    for(auto & i : big_data) {
        for(auto & j : i) {
            std::cout << j << " ";
        }

        std::cout << std::endl;
    }

    for(auto & i : big_data_2) {
        for(auto & j : i) {
            std::cout << j << " ";
        }

        std::cout << std::endl;
    }

    std::vector<std::pair<std::string, std::string>> data_to_update;
    std::vector<std::pair<std::string, std::string>> data_to_update_2;

    data_to_update.emplace_back("name", "ARTEM");
    data_to_update.emplace_back("login", "@bbbbus");

    data_to_update_2.emplace_back("id_slot", std::to_string(320));

    o.id_products = 2255;
    o.id_order = 1;
    orderManager.add(o);

    std::cout << "I want to eat in " << get_from_enum(TYPE_BUILDING::ULK) << std::endl;

    using namespace boost::locale;
    using namespace std;
    generator gen;
    locale loc=gen("");
    // Create system default locale

    locale::global(loc);
    // Make it system global

    cout.imbue(loc);
    // Set as default locale for output

    cout <<format("Today {1,date} at {1,time} we had run our first localization example") % time(0)
         <<endl;

    cout<<"This is how we show numbers in this locale "<<as::number << 103.34 <<endl;
    cout<<"This is how we show currency in this locale "<<as::currency << 103.34 <<endl;
    cout<<"This is typical date in the locale "<<as::date << std::time(0) <<endl;
    cout<<"This is typical time in the locale "<<as::time << std::time(0) <<endl;
    cout<<"This is upper case "<<to_upper("Hello World!")<<endl;
    cout<<"This is lower case "<<to_lower("Hello World!")<<endl;
    cout<<"This is title case "<<to_title("Hello World!")<<endl;
    cout<<"This is fold case "<<fold_case("Hello World!")<<endl;
}