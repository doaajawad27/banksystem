#pragma once

#include<iostream>
#include"clsUser.h"
#include<fstream>
#include"clsMainScreen.h"
#include"clsScreen.h"
#include<string>
#include"global.h"

using namespace std;


class clsLoginScreen:clsScreen
{

private:
	static void _login() {

		string username;
		string password;
		bool loginFaild = false;

		do {

			if (loginFaild) {
				cout << "\nUsername or password is wrong, try again.\n";
			}

			cout << "\nEnter username: ";
			getline(cin >> ws, username);

			cout << "\nEnter password: ";
			getline(cin >> ws, password);

			currentUser = clsUser::find(username, password);

			
			loginFaild = currentUser.isEmpty();

		} while (loginFaild);

		clsMainScreen::showMainMenu();

	}


public:
	
	static void showLoginScreen() {
		system("cls");
		_DrawScreenHeader("\tLoginScreen");
		_login();
	}
};

