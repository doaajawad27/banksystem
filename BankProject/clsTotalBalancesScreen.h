#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include"clsInputValidate.h"

using namespace std;

class clsTotalBalancesScreen: protected clsScreen
{

private:
	
	static void _printClientRecordBalanceLine(clsBankClient client) {
		cout << "\t|" << left << setw(15) << client.getAccountNumber();
		cout << "|" << left << setw(20) << client.fullName();
		cout << "|" << left << setw(12) << client.accountBalance;
	}


public:
	
	static void showTotalBalances() {

		vector<clsBankClient> vClients = clsBankClient::getClientsList();

		string title = "\t  Balances List";
		string subTitle = "\t  (" + to_string(vClients.size()) + ") Client(s).";
		
		_DrawScreenHeader(title, subTitle);

		cout << "\n\t-------------------------------------------------------";
		cout << "------------------------------------------\n" << endl;
		cout << "\t|" << left << setw(15) << "Account Number";
		cout << "|" << left << setw(20) << "Client Name";
		cout << "|" << left << setw(12) << "Balance";
		cout << "\n\t-------------------------------------------------------";
		cout << "------------------------------------------\n" << endl;

		double totalBalances = clsBankClient::getTotalBalance();

		if (vClients.size() == 0) {
			cout << "\t\t\t\tNo Clients avilable in the system!";
		}
		else {
			for (clsBankClient& c : vClients) {
				_printClientRecordBalanceLine(c);
				cout << endl;
			}
		}

		cout << "\n\t-------------------------------------------------------";
		cout << "------------------------------------------\n" << endl;

		cout << "\n\t\t\t\t  Total Balances = " << totalBalances << endl;
		cout << "\t\t\t\t ( " << clsUtil::NumberToText(totalBalances) << "\n" << endl;
		

	}



};

