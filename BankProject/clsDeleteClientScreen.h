#pragma once

#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsScreen.h"

using namespace std;

class clsDeleteClientScreen:protected clsScreen
{
private:

	static void _printClient(clsBankClient& client) {

		cout << "\n\nClient Card:";
		cout << "\n--------------------------";
		cout << "\nFirstName   :" << client.firstName;
		cout << "\nLastName    :" << client.lastName;
		cout << "\nFullName    :" << client.fullName();
		cout << "\nEmail       :" << client.email;
		cout << "\nPhone       :" << client.phone;
		cout << "\nAccount No. :" << client.getAccountNumber();
		cout << "\nPin Code    :" << client.pinCode;
		cout << "\nAccount Bal. :" << client.accountBalance;
		cout << "\n--------------------------\n\n";

	}

public:
	static void showDeleteClientScreen() {

		_DrawScreenHeader("\tDelete Client Screen");

		string accountNumber = "";
		cout << "\nplease enter account number: ";
		accountNumber = clsInputValidate::readString();

		while (!clsBankClient::isClientExist(accountNumber)) {
			cout << "\nAccount number is not found, please enter another one: ";
			accountNumber = clsInputValidate::readString();
		}
		clsBankClient client = clsBankClient::find(accountNumber);

		_printClient(client);

		char c = 'n';
		cout << "\nAre you sure you want to delete this client? (y/n)?";
		cin >> c;
		if (toupper(c) == 'Y') {
			if (client.deleteClient()) {
				cout << "\nClient deleted successfully :-)\n";
			}
			else
			{
				cout << "Errer!! client was not deleted\n";
			}

		}
	}
};

