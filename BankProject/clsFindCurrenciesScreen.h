#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"


using namespace std;

class clsFindCurrenciesScreen:protected clsScreen
{
private:

	enum enSearchBy{eCode=1,eCountry=2};

	static void _printCurrencyCard(clsCurrency currency) {

		cout << "\nCurrency Card: ";

		cout << "\n--------------------------------------\n";
		cout << "\ncountry    :" << currency.getCountry();
		cout << "\nCode       :" << currency.getCurrencyCode();
		cout << "\nName       :" << currency.getCurrencyName();
		cout << "\nRate(1$)   :" << currency.getRate();
		cout << "\n\n--------------------------------------\n";

	}

	static void _showResult(clsCurrency currency) {
		if (!currency.isEmpty()) {
			cout << "\nCurrency Found :-)\n";
			_printCurrencyCard(currency);
		}
		else {
			cout << "\nSorry, Currency is not found!! \n";
		}
	}


	static enSearchBy _readFindCurrencyOption() {
		cout << "\nFind By: [1] Code or [2] Country ? ";
		short option = clsInputValidate::readShortNumberInBetween(1, 2);
		return (enSearchBy)option;
	}

	static void searchCurrencyByCode() {

		cout << "\nPlease Enter CurrencyCode: ";
		string currencyCode = clsInputValidate::readString();

		clsCurrency currency= clsCurrency::findByCode(currencyCode);

		_showResult(currency);

	}

	static void searchCurrencyByCountry() {

		cout << "\nPlease Enter country name: ";
		string countryName = clsInputValidate::readString();

		clsCurrency currency = clsCurrency::findByCountry(countryName);

		_showResult(currency);

	}


	static void _performSearchMethod(enSearchBy option) {
		switch (option) {
			case enSearchBy::eCode:
				searchCurrencyByCode();
				break;
			case enSearchBy::eCountry:
				searchCurrencyByCountry();
				break;
		}
	}

public:
	static void showFindScreen() {

		system("cls");

		_DrawScreenHeader("\t Find Currency Screen");

		_performSearchMethod(_readFindCurrencyOption());

	}


};

