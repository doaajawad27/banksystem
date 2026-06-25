#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include"clsInputValidate.h"

using namespace std;

class clsWithdrawScreen:protected clsScreen
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

    static string _readAccountNumber() {
        cout << "\nplease enter account number? ";
        string accountNumber = clsInputValidate::readString();
        return accountNumber;
    }

public:
    static void showWithDrawScreen() {

        _DrawScreenHeader("\Withdraw Screen");

        string accountNumber = _readAccountNumber();
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "\nClient with [" << accountNumber << "] dose not exist!!";
            accountNumber = _readAccountNumber();
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        _PrintClient(client);

        float amount = 0;
        cout << "\nPlease enter withdraw amount? ";
        amount = clsInputValidate::readFloatNumber();

        char answer = 'n';
        cout << "Are you sure you want to perform this transaction? ";
        cin >> answer;

        if (toupper(answer) == 'Y') {

            if (client.withdraw(amount))
            { 
                cout << "\nAmmount withdraw sucssefully.\n ";
                cout << "\nNew Balance is: " << client.accountBalance;
            }
            else {
                cout << "\nconnet withdraw, insuffactiont balance: ";
                cout << "\n\namount to withdraw is: " << amount;
                cout << "\nYour balance is: " << client.accountBalance;
            }
           
            
        }
        else {
            cout << "\noperation was canceled.\n ";
        }

    }
    
};

