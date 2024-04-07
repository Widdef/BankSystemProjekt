// BankSystemProjekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UI.h"
#include "Client.h"
#include <map>
#include "CSVRange.h"


int main()
{
    std::srand(std::time(nullptr));
    std::map<std::string, Client*> clientsMap;
    std::ifstream file("ClientsList.csv");
    for (auto& row : CSVRange(file))
    {
        Client client(row[0], row[1], row[2], res::eNationality(std::stoi(row[3])), row[4], res::eGender(std::stoi(row[5])), Date(std::stoi(row[6]), std::stoi(row[7]), std::stoi(row[8])));
        clientsMap.insert({ client.getClientNumber(), &client });
        client.showData();
    }

    UI* menu = new UI();
    
    int option = 0;
    do {
        if (menu->isLogged())
        {
            menu->showMenu();
            menu->showMenuHandler();
        }
        else
        {
            menu->showMenuNotLogged();
            option = menu->showMenuNotLoggedHandler(clientsMap);
        }
    } while (option != EXIT_CODE || menu->isLogged());


    return 0;
}
