#pragma once
#include "Person.h"
#include "bankAccount.h"
#include <cstdlib>
#include <ctime>
#include <vector>

class Client :
    public Person
{
    std::string clientNumber;
    std::vector<bankAccount> accountList;
    int selAcc = 0;

public:
    Client(std::string name, std::string secondName, std::string surname, res::eNationality nationality, std::string idNumber, res::eGender gender, Date birthDate);
    Client();
    ~Client();
    int createNewAccount(res::eBankAccountTypes);
    int withdraw(int accNumber, int amount);
    int deposit(int accNumber, int amount);
    void showAccountList();
    std::string getClientNumber();
    void showData();
};

