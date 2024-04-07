#pragma once

#define EXIT_CODE 9


namespace res
{
	enum eNationality { Polish, German, France, UnitedKingoms };
	enum eGender { male, female };

	enum eMonthsENG { January, February, March, April, May, June, July, August, September, October, November, December };
	enum eMonthsPL {Styczen, Luty, Marzec, Kwiecien, Maj, Czerwiec, Lipiec, Sierpien, Wrzesien, Pazdziernik, Listopad, Grudzien};
	

	enum eBankAccountTypes { Debit, Credit, VAT, Technical, LAST_TYPE };
	enum eAccountStatus { Active, Closed, Lost, LAST_STATUS };


}