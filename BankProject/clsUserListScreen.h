#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include<vector>
#include"clsUser.h"
#include<string>

using namespace std;

class clsUserListScreen:protected clsScreen
{
private:
    static void _printUserRecordLine(clsUser user)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << user.username;
        cout << "| " << setw(20) << left << user.fullName();
        cout << "| " << setw(12) << left << user.phone;
        cout << "| " << setw(20) << left << user.email;
        cout << "| " << setw(12) << left << user.password;
        cout << "| " << setw(5) << left << user.permissions;

    }


public:
    static void showUsersList() {
        vector<clsUser> vUsers=clsUser::getUsersList();

        string title = "\t  User List Screen";
        string subTitle = "\t    (" + to_string(vUsers.size()) + ") Users(s).";

        _DrawScreenHeader(title, subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Username";
        cout << "| " << left << setw(20) << "Fullname";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << setw(12) << left <<"Password";
        cout << "| " << setw(5) << left << "Permissions";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

		for (clsUser& user : vUsers)
		{
			_printUserRecordLine(user);
			cout << "\n";
		}
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


    }
    




};

