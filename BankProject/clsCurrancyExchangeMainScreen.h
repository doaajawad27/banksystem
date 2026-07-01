#pragma once
#include"clsScreen.h"
#include<iostream>
#include<iomanip>

using namespace std;

class clsCurrancyExchangeMainScreen:protected clsScreen
{
private:

	enum enCurrencyExchangeOption {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3
		, eCurrencyCalculator = 4, eMainMenue = 5, 
	};

	static enCurrencyExchangeOption _readCurrencyExchangeOPtion() {
		short option;
		cout << setw(37) << "" << "Choose what do you want to do? [1-5]? ";
		option = clsInputValidate::readShortNumberInBetween(1, 5);
		return enCurrencyExchangeOption(option);
	}

	static void _goBackToCurrencyExchangeMenue() {
		cout << setw(37) << "" << "\n\press any key to go back to Currency Exchange Menue....\n";
		system("pause>0");
		clsCurrancyExchangeMainScreen::showCurrancyExchangeMainMenue();
	}

	static void _performCurrencyExchangeOption(enCurrencyExchangeOption option) {

		switch (option) {
		case enCurrencyExchangeOption::eListCurrencies:
			system("cls");
			cout << "\nwe well handel this option later\n";
			cout << "List Currencys\n";
			_goBackToCurrencyExchangeMenue();
			break;

		case enCurrencyExchangeOption::eFindCurrency:
			system("cls");
			cout << "\nwe well handel this option later\n";
			cout << "Find Currency\n";
			_goBackToCurrencyExchangeMenue();
			break;

		case enCurrencyExchangeOption::eUpdateRate:
			system("cls");
			cout << "\nwe well handel this option later\n";
			cout << "update rate\n";
			_goBackToCurrencyExchangeMenue();
			break;

		case enCurrencyExchangeOption::eCurrencyCalculator:
			system("cls");
			cout << "\nwe well handel this option later\n";
			cout << "Currency calculator\n";
			_goBackToCurrencyExchangeMenue();
			break;

		case enCurrencyExchangeOption::eMainMenue:
			system("cls");
			//nothing here
			break;

		}
	}
public:
	static void showCurrancyExchangeMainMenue() {

		system("cls");

		_DrawScreenHeader("\tCurrency Exchange Main Screen");
		cout << setw(37) << "" << left << "======================================================\n";
		cout << setw(37) << "" << left << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << "" << left << "======================================================\n";
		cout << setw(37) << "" << left << "\t[1] List Currencies.\n";
		cout << setw(37) << "" << left << "\t[2] Find Currency.\n";
		cout << setw(37) << "" << left << "\t[3] Update Rate.\n";
		cout << setw(37) << "" << left << "\t[4] Currency Calculator.\n";
		cout << setw(37) << "" << left << "\t[5] Main Menue.\n";
		cout << setw(37) << "" << left << "======================================================\n";

		_performCurrencyExchangeOption(_readCurrencyExchangeOPtion());

	}
};

