#pragma once
#include"clsScreen.h"
#include<iostream>
#include<vector>
#include"clsUSer.h"

using namespace std;
class clsDeleteUserScreen:protected clsScreen
{
private:

	static string _readUserName() {
		string username;
		cout << "\nplease enter valid user name: ";
		getline(cin >> ws, username);
		return username;
	}

	static void _printUser(clsUser& user) {
		cout << "\n\nUser card information: ";
		cout << "\nFullName: " << user.fullName();
		cout << "\nUsername: " << user.username;
		cout << "\nEmail: " << user.email;
		cout << "\nPhone: " << user.phone;
		cout << "\nPassword: " << user.password;
		cout << "\nPermission: " << user.permissions<<endl;

	}

public:

	static void showDeleteUserScreen() {
		_DrawScreenHeader("\tDelete User");
		string username = _readUserName();
		while (!clsUser::isUserExist(username)) {
			username = _readUserName();
		}

		clsUser user = clsUser::find(username);

		_printUser(user);

		char answer = 'y';
		cout << "Are you sure you want to delete this user? (y/n)";
		cin >> answer;
		if (toupper(answer) == 'Y') {

			if(user.deleteUser()) {
				cout << "\nuser deleted successfullty.\n\n";
			}
			else {
				cout << "\nfaild, somthing went wrong !!\n\n";
			}

		}
		else {
			cout << "\nthis operation was canceled!!\n\n";
		}
	}

};

