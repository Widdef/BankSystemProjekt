#include "bankAccount.h"

bankAccount::bankAccount(res::eBankAccountTypes type)
{
    this->bankCode = "12340000";
    this->typeNum = type;
    this->type = type;
    this->balance = 0;
    this->status = res::Active;

    std::srand(std::time(nullptr));
    int random_val = std::rand() % (2147483647 - 1000000000) + 1000000000;
    this->accountNumber = "000000" + std::to_string(random_val);
    random_val = std::rand() % (99 - 10) + 10;
    this->controlValue = std::to_string(random_val);
}

bankAccount::~bankAccount()
{
}

int bankAccount::getBalance()
{
    return this->balance;
}

res::eAccountStatus bankAccount::getStatus()
{
    return this->status;
}

res::eBankAccountTypes bankAccount::getType()
{
    return this->type;
}

std::string bankAccount::getAccountNumber()
{
    return this->accountNumber;
}

std::string bankAccount::getNRBFormat()
{
    std::string number = controlValue + bankCode + accountNumber;
    return number;
}

