#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"

using namespace std;

class clsShowTransactionsMenue :protected clsScreen
{
private:

	enum enTransactionsMenueOption { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eBackToMainMenue = 4 };

	static enTransactionsMenueOption _readTransactionsMenueOption() {
		short option;
		cout << setw(37) << "" << "Choose what do you want to do? [1-4]? ";
		option = clsInputValidate::readShortNumberInBetween(1, 4);
		return enTransactionsMenueOption(option);
	}

	static void _goBackToTransactionsMenue() {
		cout << setw(37) << "" << "\n\press any key to go back to Transactions Menue....\n";
		system("pause>0");
		clsShowTransactionsMenue::showTransactionsMenue();
	}

	static void _performTransactionsMenueOption(enTransactionsMenueOption option) {

		switch (option) {
		case enTransactionsMenueOption::eDeposit:
			system("cls");
			clsDepositScreen::showDepositScreen();
			_goBackToTransactionsMenue();
			break;
		case enTransactionsMenueOption::eWithdraw:
			system("cls");
			clsWithdrawScreen::showWithDrawScreen();
			_goBackToTransactionsMenue();
			break;
		case enTransactionsMenueOption::eTotalBalances:
			system("cls");
			clsTotalBalancesScreen::showTotalBalances();
			_goBackToTransactionsMenue();
			break;
		case enTransactionsMenueOption::eBackToMainMenue:
			//nothing here
			break;
		}
	}

public:
	static void showTransactionsMenue()
	{


		system("cls");

		// If user does NOT have Transactions permission, show message and return.
		if (!_checkAcessRights(clsUser::enPermissions::pTransactions)) { 
			return;
		}

		_DrawScreenHeader("\t\tTransactions  Screen");

		cout << setw(37) <<""<<left << "=======================================================\n";
		cout << setw(37) <<""<<left << "\t\t\t\tTransactions Menue \n";
		cout << setw(37) <<""<<left<< "=======================================================\n";

		cout << setw(37) <<""<<left<< "\t[1] Deposit.\n";
		cout << setw(37) << ""<<left<< "\t[2] Withdraw.\n";
		cout << setw(37) << ""<<left<< "\t[3] Total Balances.\n";
		cout << setw(37) << ""<<left<< "\t[4] Back To Main Menue.\n";

		cout << setw(37) <<""<<left << "=======================================================\n";

		_performTransactionsMenueOption(_readTransactionsMenueOption());
	}
};

