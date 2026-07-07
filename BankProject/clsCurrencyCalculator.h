#pragma once
#include"clsScreen.h"

class clsCurrencyCalculator:protected clsScreen
{

private:

	static void _printCurrencyCard(clsCurrency currency,string message) {

		cout << "\n"<<message;
		cout << "\n--------------------------------------\n";
		cout << "\ncountry    :" << currency.getCountry();
		cout << "\nCode       :" << currency.getCurrencyCode();
		cout << "\nName       :" << currency.getCurrencyName();
		cout << "\nRate(1$)   :" << currency.getRate();
		cout << "\n\n--------------------------------------\n";

	}

	static clsCurrency _readCurrency(string message) {
		cout << message;
		string currencyCode = clsInputValidate::readString();
		while (!clsCurrency::isCurrencyExist(currencyCode)) {
			cout << "\nPlease Enter Currency Code: ";
			currencyCode = clsInputValidate::readString();
		}
		return clsCurrency::findByCode(currencyCode);
	}

	static double _readAmount(string message) {
		cout << message;
		double amount = clsInputValidate::readDblNumber();
		return amount;
	}

	static void _printCalculationResult(float amount, clsCurrency currencyFrom,clsCurrency currencyTo) {

		_printCurrencyCard(currencyFrom, "Convert From: ");
		
		float amountToUsd = currencyFrom.convertToUsd(amount);

		cout << amount << " " << currencyFrom.getCurrencyCode() << " = "
			<< amountToUsd << " USD\n";

		if (currencyTo.getCurrencyCode() == "USD") {
			return;
		}
		
		cout << "\nConverting From USD To:\n";

		_printCurrencyCard(currencyTo, "To: ");

		float amountToOtherCurrency = currencyFrom.convertToOtherCurrency(amount, currencyTo);

		cout << amount << " " << currencyFrom.getCurrencyCode() << " = "
			<< amountToOtherCurrency << " " <<currencyTo.getCurrencyCode() << "\n";

	}

public: 
	static void showCalculatorScreen(){

		char answer = 'n';

		do {

			system("cls");
			_DrawScreenHeader("\t Calculator Screen");

			//read currencyFrom and CurrencyTo  user and validate it
			clsCurrency currencyFrom = _readCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency currencyTo = _readCurrency("\nPlease Enter Currency2 Code: ");
			float amount = _readAmount("\nPlease Enter Amount: ");

			_printCalculationResult(amount, currencyFrom, currencyTo);





			cout << "Do you want to perform another calculation? (y/n)?";
			cin >> answer;

		} while (toupper(answer) == 'Y');

	

	}

};

