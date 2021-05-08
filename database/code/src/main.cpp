#include <iostream>
#include "DatabaseManager.h"
#include "TableManager.h"
#include "Data.h"

int main() {
    client my_client;

    my_client.user_id = 1;
    my_client.peopleInfo.name = "Artem";
    my_client.peopleInfo.login = "@vrrf";
    my_client.peopleInfo.password = "efeef";
    my_client.peopleInfo.registration_code = 2;

    ClientManager clientManager(my_client);
    clientManager.add();
    return 0;
}