#pragma once
#include "resources.h"
#include "error_codes.h"
#include <iostream>


class Date
{
private:
	unsigned day;
	unsigned month;
	unsigned year;
	short getLenght(unsigned);
public:
	Date();
	Date(int day, int month, int year);
	~Date();
	unsigned getDay();
	int setDay(int);
	unsigned getMonth();
	int setMonth(int);
	int setMonth(res::eMonthsENG);
	int setMonth(res::eMonthsPL);
	unsigned getYear();
	friend std::ostream& operator<<(std::ostream& _stream, const Date& dt);
};

