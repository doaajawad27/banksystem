#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateClientScreen :protected clsScreen

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

    static void _readClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.firstName = clsInputValidate::readString();

        cout << "\nEnter LastName: ";
        Client.lastName = clsInputValidate::readString();

        cout << "\nEnter Email: ";
        Client.email = clsInputValidate::readString();

        cout << "\nEnter Phone: ";
        Client.phone = clsInputValidate::readString();

        cout << "\nEnter PinCode: ";
        Client.pinCode = clsInputValidate::readString();

        cout << "\nEnter Account Balance: ";
        Client.accountBalance = clsInputValidate::readFloatNumber();
    }

public:

    static void showUpdateClientScreen()
    {
        if (!_checkAcessRights(clsUser::pUpdateClient)) {
            return;
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string accountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client = clsBankClient::find(accountNumber);

        _PrintClient(client);

        cout << "\nAre you sure you want to update this client y/n? ";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            _readClientInfo(client);

            clsBankClient::enSaveResults saveResult;

            saveResult = client.save();

            switch (saveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(client);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

