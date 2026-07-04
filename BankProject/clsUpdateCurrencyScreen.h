#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"


using namespace std;

class clsUpdateCurrencyScreen:protected clsScreen
{

private:

	static void _printCurrencyCard(clsCurrency currency) {

		cout << "\nCurrency Card: ";
		cout << "\n--------------------------------------\n";
		cout << "\ncountry    :" << currency.getCountry();
		cout << "\nCode       :" << currency.getCurrencyCode();
		cout << "\nName       :" << currency.getCurrencyName();
		cout << "\nRate(1$)   :" << currency.getRate();
		cout << "\n\n--------------------------------------\n";

	}

public:

	static void showUpdateCurrencyScreen() {

		_DrawScreenHeader("\t  Update Currency Rate Screen");

		cout << "\nPlease Enter Currency Code: ";
		string currencyCode = clsInputValidate::readString();

		clsCurrency currency = clsCurrency::findByCode(currencyCode);

		if (!currency.isEmpty()) {
			_printCurrencyCard(currency);
		} else {
			cout << "\n\nCurrency not found!\n\n";
			return;
		}

		char result = 'n';
		cout << "\nAre you sure you want to update this rate?  ";
		cin >> result;

		if (toupper(result)=='Y')
		{

			cout << "\nUpdate Currency Rate: \n";
			cout << "-----------------------------\n";
			cout << "\nPlease Enter New Rate: ";
			float newRate = clsInputValidate::readDblNumber();
			currency.updateRate(newRate);
			_printCurrencyCard(currency);

		}

		else 
		
		{
			cout << "operation was canceled by user\n";
		}


	}
};

