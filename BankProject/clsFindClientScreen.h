#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.firstName;
        cout << "\nLastName    : " << Client.lastName;
        cout << "\nFull Name   : " << Client.fullName();
        cout << "\nEmail       : " << Client.email;
        cout << "\nPhone       : " << Client.phone;
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nPassword    : " << Client.pinCode;
        cout << "\nBalance     : " << Client.accountBalance;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindClientScreen()
    {
        if (!_checkAcessRights(clsUser::pFindClient)) {
            return;
        }

        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::readString();
        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::readString();
        }

        clsBankClient Client1 = clsBankClient::find(AccountNumber);

        if (!Client1.isEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);

    }

};

