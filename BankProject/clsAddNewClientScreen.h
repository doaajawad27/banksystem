#pragma once

#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsScreen.h"

using namespace std;


class clsAddNewClientScreen:protected clsScreen
{

private:

	static void _readClientInfo(clsBankClient& client) {
		cout << "Enter first name: ";
		client.firstName = clsInputValidate::readString();

		cout << "Enter last name: ";
		client.lastName = clsInputValidate::readString();

		cout << "Enter email: ";
		client.email = clsInputValidate::readString();

		cout << "Enter phone number: ";
		client.phone = clsInputValidate::readString();

		cout << "Enter Pin code: ";
		client.pinCode = clsInputValidate::readString();

		cout << "Enter account balance: ";
		client.accountBalance = clsInputValidate::readDblNumber();
	}

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
		cout << "\n--------------------------\n";

	}

public:

	static void showAddNewClienteScreen() {

		if (!_checkAcessRights(clsUser::pAddNewClient)) {
			return;
		}

		_DrawScreenHeader("\t Add New Client Screen");
		string accountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		accountNumber = clsInputValidate::readString();
		while (clsBankClient::isClientExist(accountNumber)) {
			cout << "\nAccount Number is already used,please enter another account number? ";
			accountNumber = clsInputValidate::readString();
		}

		clsBankClient newClient = clsBankClient::getAddNewClientObject(accountNumber);
		_readClientInfo(newClient);

		clsBankClient::enSaveResults saveResult;
		saveResult = newClient.save();

		switch (saveResult) {
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\nAccount Added Successfully :-)";
			_printClient(newClient);
			break;
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\nAccount was not saved because its empty";
			break;
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
			cout << "\nAccount was not saved because account number is exist";
		}
	}

};

