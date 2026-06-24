#pragma once

#include"clsScreen.h"
#include<iostream>
#include"clsUser.h"
#include<vector>
#include"clsInputValidate.h"


using namespace std;
class claAddNewUserScreen:protected clsScreen
{
private:
	
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

		user.permissions=_readPermissionToSet();

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

		cout << "\nDelete Client ? ";
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

		cout << "\nLogin Register ? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
			permissions += clsUser::enPermissions::pLoginRegister;
		return permissions;
	}

	static void _printUser(clsUser& user) {
		cout << "\n\nUser card information: " ;
		cout << "\nFullName: " << user.fullName();
		cout << "\Username: " << user.username;
		cout << "\Email: " << user.email;
		cout << "\Phone: " << user.phone;
		cout << "\PAssword: " << user.password;
		cout << "\Permission: " << user.permissions;

	}

	

public:

	static void showAddNewUser() {

		_DrawScreenHeader("\tAdd New User Screen");

		string username = "";

		cout << "\nPlease enter username? ";
		getline(cin >> ws, username);

		while (clsUser::isUserExist(username)) {
			cout << "user is already exit, please enter another username? ";
			getline(cin >> ws, username);
		}

		clsUser user=clsUser::getAddNewUserObject(username);
		_readUserInfo(user);

		clsUser::enSaveResults saveResult = user.save();

		switch (saveResult) {

		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser addedd sucessfully. \n";
			break;
		}
			
		case clsUser::enSaveResults::svFaildUserExicts:
		{
			cout << "faild becase user is already exist.\n";
			break;
		}
			
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "faild becase user is empty.\n";
			break;
		}
			
		}
	}
};

