#pragma once
#include"clsScreen.h"


class clsTransferScreen:clsScreen
{

private:

	static void _printAccountInfo(clsBankClient& client) {
		cout << "\n\nClient Card:";
		cout << "\n-----------------------";
		cout << "\nFull Name   : " << client.fullName();
		cout << "\nAcc. Number :" << client.getAccountNumber();
		cout << "\nBalance     :" << client.accountBalance;
		cout << "\n-----------------------\n"; 
	}

public:
	static void showTransferScreen() {
		_DrawScreenHeader("\t Transfer Screen");
		string accountNumberFrom;
		cout << "\nPlease Enter Account Number to transfer from: ";
		accountNumberFrom = clsInputValidate::readString();

		while (!clsBankClient::isClientExist(accountNumberFrom)) {
			cout << "\nAccount Number is not exist, Please Enter  another Account Number to transfer from: ";
			accountNumberFrom = clsInputValidate::readString();
		}

		clsBankClient clientFrom = clsBankClient::find(accountNumberFrom);

		_printAccountInfo(clientFrom);

		string accountNumberTo;

		cout << "\n\nPlease Enter Account Number to transfer to: ";
		accountNumberTo = clsInputValidate::readString();
		while (!clsBankClient::isClientExist(accountNumberTo)) {
			cout << "\nAccount Number is not exist, Please Enter  another Account Number to transfer to: ";
			accountNumberTo = clsInputValidate::readString();
		}

		clsBankClient clientTo = clsBankClient::find(accountNumberTo);
		_printAccountInfo(clientTo);

		double transferAmount;
		cout << "Enter the amount you want to transfer?";
		transferAmount = clsInputValidate::readDblNumber();

		char answer;
		cout << "\nAre you sure you want to perform this transaction?(y/n)\n";
		cin >> answer;

		if (toupper(answer) == 'Y') {
			if (clientFrom.accountBalance < transferAmount) {
				cout << "\n\ncant transfer amount because account balance less than amount!!!\n";
			}
			else {
				clientFrom.whithdraw(transferAmount);
				clientTo.deposit(transferAmount);
				_printAccountInfo(clientFrom);
				_printAccountInfo(clientTo);
			}
			
		}
		else {
			cout << "operation was cancelled!!\n";
		}

		

	}
};

