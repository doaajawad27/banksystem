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

	static string _readAccountNumber(string message) {
		string accountNumber;
		cout << "\n" << message << endl;
		accountNumber = clsInputValidate::readString();
		while (!clsBankClient::isClientExist(accountNumber)) {
			cout << "\nAccount Number is not exist, Please Enter  another Account Number : ";
			accountNumber = clsInputValidate::readString();
		}
		return accountNumber;
	}

public:
	static void showTransferScreen() {
		_DrawScreenHeader("\t Transfer Screen");
		
		clsBankClient clientFrom = clsBankClient::find(_readAccountNumber("Please Enter Account Number to transfer from: "));
		_printAccountInfo(clientFrom);


		clsBankClient clientTo = clsBankClient::find(_readAccountNumber("\nPlease Enter Account Number to transfer to: "));
		_printAccountInfo(clientTo);

		
		cout << "Enter the amount you want to transfer? ";
		double transferAmount = clsInputValidate::readDblNumber();

		char answer;
		cout << "\nAre you sure you want to perform this transaction?(y/n)\n";
		cin >> answer;

		if (toupper(answer) == 'Y') {
			if (clientFrom.transfer(transferAmount, clientTo)) {
				cout << "\ntransfer done sucessfully.\n";
				_printAccountInfo(clientFrom);
				_printAccountInfo(clientTo);
				clientFrom.transferRegister(transferAmount, clientTo, currentUser.username);
			}
			else {
				cout << "\nsorry, cant transfer amount not enogth.\n";
			}
			
		}
		else {
			cout << "operation was cancelled!!\n";
		}

	}
};

