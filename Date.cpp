#include "Date.h"


std::ostream& operator<<(std::ostream& _stream, const Date& dt)
{
	_stream << dt.day << "-" << dt.month << "-" << dt.year;
	return _stream;
}

short Date::getLenght(unsigned month)
{
	try {
		if (month > 12)
			throw (month);
		//rok przestêpny
		if (month == 2) {
			if (this->year % 4 == 0 && (this->year % 100 != 0 || this->year % 400 == 0))
				return 29;
			else
				return 28;
		}
		//miesi¹ce maj¹ce 31 dni
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			|| month == 10 || month == 12)
			return 31;
		else return 30;
	}
	catch (int number) {
		std::cout << "\n\n[" << WRONG_MONTH_VALUE << "]Zla wartosc dla wartosci miesiac. Wartosc: " << number;
		return WRONG_MONTH_VALUE;
	}
}

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1900;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date()
{
}

unsigned Date::getDay()
{
	return this->day;
}

int Date::setDay(int day)
{
	try {
		int monthLenght = this->getLenght(this->month);
		if (monthLenght == WRONG_MONTH_VALUE)
			throw (WRONG_MONTH_VALUE);
		if ( monthLenght > day)
			throw (WRONG_DAY_VALUE);
		this->day = day;
		return 0;
	}
	catch (int value)
	{
		std::cout << "\n\n[" << WRONG_DAY_VALUE << "Podano niewlasciwa wartosc dnia {" << day
			<< " dla miesiaca " << this->month;
		return value;
	}
}

unsigned Date::getMonth()
{
	return this->month;
}

int Date::setMonth(int month)
{
	try {
		if (month > 12)
			throw (WRONG_MONTH_VALUE);
		this->month = month;
		return 0;
	}
	catch (int value)
	{
		std::cout << "\n\n[" << WRONG_MONTH_VALUE << "]Zla wartosc dla wartosci miesiac. Wartosc: " << value;
		return WRONG_MONTH_VALUE;
	}
}

int Date::setMonth(res::eMonthsENG month)
{
	//TODO error handling
	this->month = month;
	return 0;
}

int Date::setMonth(res::eMonthsPL month)
{
	//TODO error handling
	this->month = month;
	return 0;
}

unsigned Date::getYear()
{
	return this->year;
}
