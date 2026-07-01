#pragma once
#include<iostream>
#include<iomanip>

#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsUtil.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsShowTransactionsMenue.h"
#include"clsShowManageUsersMenue.h"
#include"clsShowLoginRegisterScreen.h"
#include"clsCurrancyExchangeMainScreen.h"
#include"global.h"


using namespace std;

class clsMainScreen:protected clsScreen
{


	enum enMainMenuOption {eListClient=1,eAddNewClient=2,eDeleteClient=3
							,eUpdateClient=4,eFindClient=5,eShowTransactionsMenue=6
							,eManageUSers=7,eLoginRegister=8,eCurrancyExchange=9,eExit=10};

	static enMainMenuOption _readMainMenuOPtion() {
		short option;
		cout << setw(37) << "" << "Choose what do you want to do? [1-10]? ";
		option = clsInputValidate::readShortNumberInBetween(1,9);
		return enMainMenuOption(option);
	}

	static void _goBackToMainMenue() {
		cout <<setw(37)<<"" << "\n\press any key to go back to Main Menue....\n";
		system("pause>0");
		clsMainScreen::showMainMenu();
	}

	static void _showAllClientsScreen() {

		clsClientListScreen::showClientsList();
	}

	static void _showAddNewClientsScreen() {
		clsAddNewClientScreen::showAddNewClienteScreen();
	}

	static void _showDeleteClientScreen() {
		clsDeleteClientScreen::showDeleteClientScreen();
	}

	static void _showUpdateClientScreen() {
		clsUpdateClientScreen::showUpdateClientScreen();
	}

	static void _showFindClientScreen() {
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _showTransactoionMenue() {
		clsShowTransactionsMenue::showTransactionsMenue();
	}

	static void _showManageUsersScreen() {
		clsShowManageUsersMenue::showManageUsersMenue();

	}


	static void _showLoginRegisterScreen() {
		clsShowLoginRegisterScreen::showLoginRegisterScreen();
	}


	static void _showExitScreen() { 
		currentUser = clsUser::find("", "");
	}

	static void _showCurrancyExchangeMenue() {
		clsCurrancyExchangeMainScreen::showCurrancyExchangeMainMenue();
	}

	static void _performMainMenuOption(enMainMenuOption option) {
		
		switch (option) {

			case enMainMenuOption::eListClient:
				system("cls");
				_showAllClientsScreen();
				_goBackToMainMenue();
				break;

			case enMainMenuOption::eAddNewClient:
				system("cls");
				_showAddNewClientsScreen();
				_goBackToMainMenue();
				break;

			case enMainMenuOption::eDeleteClient:
				system("cls");
				_showDeleteClientScreen();
				_goBackToMainMenue();
				break;

			case enMainMenuOption::eUpdateClient:
				system("cls");
				_showUpdateClientScreen();
				_goBackToMainMenue();
				break;

			case enMainMenuOption::eFindClient:
				system("cls");
				_showFindClientScreen();
				_goBackToMainMenue();
				break;

			case enMainMenuOption::eShowTransactionsMenue:
				system("cls");
				_showTransactoionMenue();
				_goBackToMainMenue();
				break;
			case enMainMenuOption::eManageUSers:
				system("cls");
				_showManageUsersScreen();
				_goBackToMainMenue();
				break;

			case enMainMenuOption::eLoginRegister:
				system("cls");
				_showLoginRegisterScreen();
				_goBackToMainMenue();
				break;

			case enMainMenuOption::eCurrancyExchange:
				system("cls");
				_showCurrancyExchangeMenue();
				_goBackToMainMenue();
				break;

			case enMainMenuOption::eExit:
				system("cls");
				_showExitScreen();
				break;
		}
	}

	

public: 

	static void showMainMenu() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << "" << left << "============================================================\n";
		cout << setw(37) << "" << left << "\t\t\tMain Menu\n";
		cout << setw(37) << "" << left << "============================================================\n";
		cout << setw(37) << "" << left << "\t[1] Show Client List.\n";
		cout << setw(37) << "" << left << "\t[2] Add New CLient Client.\n";
		cout << setw(37) << "" << left << "\t[3] Delete Client.\n";
		cout << setw(37) << "" << left << "\t[4] Update Client.\n";
		cout << setw(37) << "" << left << "\t[5] Find Client.\n";
		cout << setw(37) << "" << left << "\t[6] Transactions.\n";
		cout << setw(37) << "" << left << "\t[7] Manage Users.\n";
		cout << setw(37) << "" << left << "\t[8] Login Register.\n";
		cout << setw(37) << "" << left << "\t[9] Currancy Exchange.\n";
		cout << setw(37) << "" << left << "\t[10] Exit.\n";
		cout << setw(37) << "" << left << "============================================================\n";

		_performMainMenuOption(_readMainMenuOPtion());


	}

};

