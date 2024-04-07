#include "UI.h"

UI::UI()
{
	loggedClient = "0";
}

UI::~UI()
{
}

int UI::login(std::map<std::string, Client*>& clientList)
{
	std::cout << "\nPodaj numer klienta: ";
	getline(std::cin, this->loggedClient);
	if (loggedClient != "")
	{
		this->currClient = clientList[this->loggedClient];
		return 0;
	}
	return 100000;
	//TODO ob³uga b³êdów.
}

int UI::logout()
{
	loggedClient = "0";
	//TODO ob³uga b³êdów.
	return 0;
}

int UI::showMenu()
{
	std::cout << "1. Lista rachunkow.\n";
	std::cout << "2. Otworz nowy rachunek.\n";
	std::cout << "3. Wybierz rachunek.\n";
	std::cout << "9. Wyloguj.\n";
	return 0;
}

void UI::showMenuHandler()
{
	std::string option = "0";
	std::string value = "0";
	getline(std::cin, option);
	switch (stoi(option))
	{
	case 1: currClient->showAccountList(); break;
	case 2: selectAccType(); currClient->showAccountList(); break;
	case 3: 
		std::cout << "Podaj numer rachunku: ";
		getline(std::cin, value); 
		showAccountMenuHandler(stoi(value)); break;
	case 9: logout(); break;
	}
}

int UI::showMenuNotLogged()
{
	std::cout << "1. Zaloguj sie\n";
	std::cout << "2. Dodaj nowego usera\n";
	std::cout << "3. Wyswietl wszystkich userow\n";
	std::cout << "9. Wyjscie\n";


	//Kod powrotu
	return 0;
}

int UI::showMenuNotLoggedHandler(std::map<std::string, Client*>& clientList)
{
	std::string option = "0";
	getline(std::cin, option);
	switch (stoi(option))
	{
	case 1: this->login(clientList); break;
	case 2: 
		addNewUser(clientList);
		break;
	case 3:
		showAllUsers(clientList); break;
	case EXIT_CODE: break;
	}
	return stoi(option);
}

void UI::showAccountMenu()
{
	std::cout << "1. Wplac na rachunek.\n";
	std::cout << "2. Wyplac z rachunku.\n";
	std::cout << "9. Cofnij.\n";
}

void UI::showAccountMenuHandler(int accNumber)
{
	std::string option = "0";
	std::string amount = "0";
	do {
		showAccountMenu();
		getline(std::cin, option);
		switch (stoi(option))
		{
		case 1: 
			std::cout << "Podaj kwote do wplaty: ";
			getline(std::cin, amount);
			this->currClient->deposit(accNumber, stoi(amount)); break;
		case 2:
			std::cout << "Podaj kwote do wyplaty: ";
			getline(std::cin, amount);
			this->currClient->withdraw(accNumber, stoi(amount)); break;
		case 9: break;
		}

	} while (option != "9");
}

bool UI::isLogged()
{
	if (loggedClient == "0")
		return false;
	return true;
}

void UI::selectAccType()
{
	for (int elem = res::Debit; elem != res::eBankAccountTypes::LAST_TYPE; elem++)
	{
		res::eBankAccountTypes type = static_cast<res::eBankAccountTypes>(elem);
		std::cout << type << " ";
	}

	std::string line = "";
	std::cout << "Podaj typ rachunku: ";
	getline(std::cin, line);

	this->currClient->createNewAccount(res::eBankAccountTypes(std::stoi(line)));

}

void UI::showAllUsers(std::map<std::string, Client*>& clientList)
{
	for (const auto& el : clientList)
	{
		el.second->showData();
	}
}

void UI::addNewUser(std::map<std::string, Client*>& clientList)
{
	Client* cli = new Client();
	clientList.insert(std::map< std::string, Client*>::value_type(cli->getClientNumber(), cli));
}