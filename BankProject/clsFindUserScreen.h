#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen:protected clsScreen
{
private:

	static void _printUser(clsUser& user) {
		cout << "\n\nUser card information: ";
		cout << "\nFullName: " << user.fullName();
		cout << "\nUsername: " << user.username;
		cout << "\nEmail: " << user.email;
		cout << "\nPhone: " << user.phone;
		cout << "\nPAssword: " << user.password;
		cout << "\nPermission: " << user.permissions<<"\n\n";

	}

public:

    static void ShowFindUserScreen()
    {

        _DrawScreenHeader("\tFind User Screen");

        string username;
        cout << "\nPlease Enter user Name: ";
        username = clsInputValidate::readString();
        while (!clsUser::isUserExist(username))
        {
            cout << "\nusername is not found, choose another one: ";
            username = clsInputValidate::readString();
        }

        clsUser user = clsUser::find(username);

        if (!user.isEmpty())
        {
            cout << "\nuser Found :-)\n";
        }
        else
        {
            cout << "\nuser Was not Found :-(\n";
        }

        _printUser(user);

    }


};

