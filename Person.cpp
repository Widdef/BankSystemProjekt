#include "Person.h"

std::string Person::getName()
{
	return this->name;
}
std::string Person::getSecondName() 
{
	return this->secondName;
}
std::string Person::getSurname() 
{
	return this->surname;
}
std::string Person::getIDnumber()
{
	return this->IDnumber;
}
res::eGender Person::getGender()
{
	return res::eGender();
}
Date Person::getBirthDate()
{
	return this->birthDate;
}
res::eNationality Person::getNationality()
{
	return this->nationality;
}

