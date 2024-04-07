#pragma once
#include <iostream>
#include <string>
#include "Client.h"
#include <map>

class UI
{
private:
	std::string loggedClient;
	Client* currClient;

public:
	UI();
	~UI();
	int login(std::map<std::string, Client*>&);
	int logout();
	int showMenu();
	void showMenuHandler();
	int showMenuNotLogged();
	int showMenuNotLoggedHandler(std::map<std::string, Client*>&);
	void showAccountMenu();
	void showAccountMenuHandler(int accNumber);
	bool isLogged();
	void selectAccType();
	void showAllUsers(std::map<std::string, Client*>& clientList);
	void addNewUser(std::map<std::string, Client*>& clientList);
};

