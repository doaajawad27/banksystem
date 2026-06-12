#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"
#include"clsUserListScreen.h"
#include"claAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

using namespace std;

class clsShowManageUsersMenue:protected clsScreen
{
private:
	enum enManageUsersMenueOptions{eListUSers=1,eAddNewUser=2,eDeleteUsers=3,eUpdateUsers=4,eFindUsers=5,eMainMenue=6};

	static enManageUsersMenueOptions readManageUsersOption() {
		cout << setw(37) << "" << "please enter what do you want to do?[1-6]? ";
		int option = clsInputValidate::readDblNumberInBetween(1, 6);
		return enManageUsersMenueOptions(option);
	}

	static void _goBackToManageUsersMenue() {

		cout<< setw(37) << "" << "Please enter to go back to Manage Users Menue... ";
		system("pause>0");
		clsShowManageUsersMenue::showManageUsersMenue();
		
	}

	static void _showListUsersScreen() {
		clsUserListScreen::showUsersList();
	}

	static void _showAddNewUserScreen() {
		claAddNewUserScreen::showAddNewUser();
	}

	static void _showDeleteUserScreen() {
		clsDeleteUserScreen::showDeleteUserScreen();
	}

	static void _showUpdateUserScreen() {
		clsUpdateUserScreen::showUpdateUserScreen();
	}

	static void _showFindUserScreen() {
		clsFindUserScreen::ShowFindUserScreen();
	}


	static void _performManageUsersMenueOption(enManageUsersMenueOptions manageUSersOPtion) {
		
		switch (manageUSersOPtion) {

		case clsShowManageUsersMenue::eListUSers:
			system("cls");
			_showListUsersScreen();
			_goBackToManageUsersMenue();
			break;

		case clsShowManageUsersMenue::eAddNewUser:
			system("cls");
			_showAddNewUserScreen();
			_goBackToManageUsersMenue();
			break;

		case clsShowManageUsersMenue::eDeleteUsers:
			system("cls");
			_showDeleteUserScreen();
			_goBackToManageUsersMenue();
			break;

		case clsShowManageUsersMenue::eUpdateUsers:
			system("cls");
			_showUpdateUserScreen();
			_goBackToManageUsersMenue();
			break;

		case clsShowManageUsersMenue::eFindUsers:
			system("cls");
			_showFindUserScreen();
			_goBackToManageUsersMenue();
			break;

		case clsShowManageUsersMenue::eMainMenue:
			//nothing here
			break;
		
		}


	}

public :

	static void showManageUsersMenue() {

		system("cls");

		_DrawScreenHeader("\tManage Users Screen");

		cout << setw(37) << "" << left << "=======================================================\n";
		cout << setw(37) << "" << left << "\t\t\t\tManage Users Menue \n";
		cout << setw(37) << "" << left << "=======================================================\n";

		cout << setw(37) << "" << left << "\t[1] List Users.\n";
		cout << setw(37) << "" << left << "\t[2] Add New User.\n";
		cout << setw(37) << "" << left << "\t[3] Delete User.\n";
		cout << setw(37) << "" << left << "\t[4] Update User.\n";
		cout << setw(37) << "" << left << "\t[5] Find User.\n";
		cout << setw(37) << "" << left << "\t[6] Main Menue.\n";

		cout << setw(37) << "" << left << "=======================================================\n";

		_performManageUsersMenueOption(readManageUsersOption());

	}

};

