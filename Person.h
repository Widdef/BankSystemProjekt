#pragma once
#include <string>
#include "resources.h"
#include "Date.h"

class Person
{
protected:
	std::string name;
	std::string secondName;
	std::string surname;
	res::eNationality nationality;
	std::string IDnumber;
	res::eGender gender;
	Date birthDate;


public:
	std::string getName();
	std::string getSecondName();
	std::string getSurname();
	std::string getIDnumber();
	res::eNationality getNationality();
	res::eGender getGender();
	Date getBirthDate();
};

