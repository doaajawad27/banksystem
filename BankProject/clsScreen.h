#pragma once
#include<iostream>
#include"global.h"
#include"clsUser.h"
#include"clsDate.h"


using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string title, string subTitle = "") {
		cout << "\t\t\t\t\t--------------------------------------------------------";
		cout << "\n\t\t\t\t\t " << title;
		if (subTitle != "")
			cout << "\n\t\t\t\t\t " << subTitle;
		cout << "\n\t\t\t\t\t--------------------------------------------------------\n";
		cout << "\n\t\t\t\t\t" << "User: " << currentUser.username;
		cout << "\n\t\t\t\t\t" << "Date: " << clsDate::dateToString(clsDate::GetSystemDate())<<"\n\n";

	}

	static bool _checkAcessRights(clsUser::enPermissions permissions) {

		if (currentUser.checkUserPermissions(permissions)) {
			return true;
		}

		else {
			cout << "\t\t\t\t--------------------------------------------------------------------------------\n";
			cout << "\n\t\t\t\tYou don't have the permissions to do this action,contact your administrator :-(\n";
			cout << "\n\t\t\t\t--------------------------------------------------------------------------------\n";
			return false;
		}
	
	}
};

