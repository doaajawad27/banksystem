#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include<string>

using namespace std;
class clsUpdateUserScreen:clsScreen
{

private:

	static void _printUser(clsUser& user) {
		cout << "\n\nUser card information: ";
		cout << "\nFullName: " << user.fullName();
		cout << "\nUsername: " << user.username;
		cout << "\nEmail: " << user.email;
		cout << "\nPhone: " << user.phone;
		cout << "\nPassword: " << user.password;
		cout << "\nPermission: " << user.permissions << endl;

	}

	static void _readUserInfo(clsUser& user) {

		cout << "\nPlease Enter FirstName: ";
		user.firstName = clsInputValidate::readString();

		cout << "\nPlease Enter LastName: ";
		user.lastName = clsInputValidate::readString();

		cout << "\nPlease Enter Email: ";
		user.email = clsInputValidate::readString();

		cout << "\nPlease Enter Phone: ";
		user.phone = clsInputValidate::readString();

		cout << "\nPlease Enter password: ";
		user.password = clsInputValidate::readString();

		user.permissions = _readPermissionToSet();

	}

	static int _readPermissionToSet() {
		int permissions = 0;
		char answer = 'n';

		cout << "Do you want to give full access? (y/n)? ";
		cin >> answer;

		if (toupper(answer) == 'Y') {

			return -1;

		}

		cout << "\nDo you want to give access to: \n ";

		cout << "\nShow Client List? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
			permissions += clsUser::enPermissions::pListClients;

		cout << "\nAdd New Client ? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
			permissions += clsUser::enPermissions::pAddNewClient;

		cout << "\Delete Client ? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
			permissions += clsUser::enPermissions::pDeleteClient;

		cout << "\nUpdate Client ? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
			permissions += clsUser::enPermissions::pUpdateClient;

		cout << "\nFind Client ? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
			permissions += clsUser::enPermissions::pFindClient;

		cout << "\nTransactoins ? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
			permissions += clsUser::enPermissions::pTransactions;

		cout << "\nManage Users ? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
			permissions += clsUser::enPermissions::pManageUSers;

		return permissions;
	}


public:

	static void showUpdateUserScreen() {

		_DrawScreenHeader("\tUpdate User");
		string username = "";

		cout << "\nplease enter username: ";
		getline(cin >> ws, username);

		while (!clsUser::isUserExist(username)) {
			cout << "\nuser is not found, please enter another username: ";
			getline(cin >> ws, username);
		}
		
		clsUser user = clsUser::find(username);

		_printUser(user);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";

		_readUserInfo(user);

		char answer = 'n';
		cout << "\nAre you sure you want to update this user info? (y\n)? ";
		cin >> answer;
		if (toupper(answer) == 'Y') {
			clsUser::enSaveResults saveResult = user.save();

			switch (saveResult) {

			case clsUser::enSaveResults::svSucceeded:
				cout << "\nuser updated sucssesfully.\n";
				break;

			case clsUser::enSaveResults::svFaildUserExicts:
				cout << "\nfaild somtehing  went wrong !!.\n";
				break;
			}
		}
		else {
			cout << "\nOperation was  canceld!!\n";
		}

	}

};

