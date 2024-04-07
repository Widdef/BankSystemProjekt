#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
#include "resources.h"

class bankAccount
{
private:
	std::string controlValue;
	std::string bankCode;
	res::eBankAccountTypes type;
	std::string typeNum;
	std::string accountNumber;
	int balance;
	res::eAccountStatus status;
public:
	bankAccount(res::eBankAccountTypes);
	~bankAccount();
	int getBalance();
	res::eAccountStatus getStatus();
	res::eBankAccountTypes getType();
	std::string getAccountNumber();
	std::string getNRBFormat();
	friend class Client;
};

