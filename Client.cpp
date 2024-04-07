#include "Client.h"


Client::Client(std::string name, std::string secondName, std::string surname, res::eNationality nationality, std::string idNumber, res::eGender gender, Date birthDate)
{
	this->name = name;
	this->secondName = secondName;
	this->surname = surname;
	this->nationality = nationality;
	this->IDnumber = idNumber;
	this->birthDate = birthDate;
	this->clientNumber = std::to_string(std::rand() % (1000000 - 100000) + 100000);
}

Client::Client()
{
	std::cout << "\nPodaj imie: ";
	std::string name = "";
	getline(std::cin, name);
	this->name = name;
	std::cout << "\nPodaj drugie imie (jezeli posiadasz): ";
	std::string secondName = "";
	getline(std::cin, secondName);
	this->secondName = secondName;
	std::cout << "\nPodaj nazwisko: ";
	std::string surname = "";
	getline(std::cin, surname);
	this->surname = surname;
	std::cout << "\nPodaj kraj pochodzenia: \n0-Polska\n1-Niemcy\n2-Francja\n3-WielkaBrytania\n\n";
	std::string nationality = "";
	getline(std::cin, nationality);
	this->nationality = res::eNationality(stoi(nationality));
	std::cout << "\nPodaj id dokumentu: ";
	std::string idNumber = "";
	getline(std::cin, idNumber);
	this->IDnumber = idNumber;
	//TODO walidacja wartoœci czy s¹ sensowne. 
	std::cout << "\nPodaj dzien urodzenia: ";
	std::string day = "";
	getline(std::cin, day);
	std::cout << "\nPodaj miesiac urodzenia: ";
	std::string month = "";
	getline(std::cin, month);
	std::cout << "\nPodaj rok urodzenia: ";
	std::string year = "";
	getline(std::cin, year);
	this->birthDate = Date(stoi(day),stoi(month),stoi(year));
	this->clientNumber = std::to_string(std::rand() % (1000000 - 100000) + 100000);
}

Client::~Client()
{
}

int Client::createNewAccount(res::eBankAccountTypes type)
{
	accountList.push_back(bankAccount(type));
	return 0;
}

int Client::withdraw(int accNumber, int amount)
{
	try {
		if (amount > this->accountList[accNumber].getBalance())
			throw(NOT_ENOUGH_MONEY);
		this->accountList[accNumber].balance -= amount;
		std::cout << "Wyplacono: " << amount << " na rachunku pozostalo: "
			<< this->accountList[accNumber].balance << std::endl;
		return 0;
	
	}
	catch (int value)
	{
		std::cout << "\n\n[" << value << "]Niewystarczajaca ilosc srodkow!\n";
		return value;
	}
}

int Client::deposit(int accNumber, int amount)
{
	this->accountList[accNumber].balance += amount;
	std::cout << "Wplacono: " << amount << " na rachunku znajduje sie: "
		<< this->accountList[accNumber].balance << std::endl;
	return 0;
}

void Client::showAccountList()
{
	int i = 0;
	std::cout << std::endl;
	for (bankAccount acc : accountList)
	{
		std::cout << i << ". Typ: " << acc.getType() << " Numer: " 
			<< acc.getNRBFormat() << "\nBilans: " << acc.getBalance() 
			<< " monet\n";
	}
}

std::string Client::getClientNumber()
{
	return this->clientNumber;
}

void Client::showData()
{
	std::cout << this->name << "  " << this->surname << "  " << clientNumber << std::endl;
}


