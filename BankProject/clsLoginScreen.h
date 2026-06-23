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

	static bool _login() {

		string username;
		string password;
		bool loginFaild = false;

		short faildLoginCount = 0;
		
		do {


			if (loginFaild) {
				faildLoginCount++;

				cout << "\nUsername or password is wrong, try again.\n";
				cout << "you have " << (3 - faildLoginCount) << " trials to login.\n";
				
			}

			if (faildLoginCount == 3) {
				cout << "\nyour are locked after 3 faild trails.\n\n";
				return false;
			}

			cout << "\nEnter username: ";
			getline(cin >> ws, username);

			cout << "\nEnter password: ";
			getline(cin >> ws, password);

			currentUser = clsUser::find(username, password);

			
			loginFaild = currentUser.isEmpty();

		} while (loginFaild);

		currentUser.registerLogin();
		clsMainScreen::showMainMenu();
		return true;

	}


public:
	
	static bool showLoginScreen() {
		system("cls");
		_DrawScreenHeader("\tLoginScreen");

		return _login();

	}
};

