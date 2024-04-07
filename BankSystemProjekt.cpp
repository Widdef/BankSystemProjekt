// BankSystemProjekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UI.h"
#include "Client.h"
#include <map>


int main()
{
    std::srand(std::time(nullptr));
    Client cli1("Mark", "", "Kowalski", res::German, "ABC123", res::male, Date(13, 4, 1993));
    cli1.showData();
    Client cli2("Damian", "", "Kowalski", res::Polish, "ADC1337", res::male, Date(12, 3, 1999));
    cli2.showData();

    std::map<std::string, Client*> clientsMap{ {cli1.getClientNumber(), &cli1}, {cli2.getClientNumber(), &cli2} };

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
