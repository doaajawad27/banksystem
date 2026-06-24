#pragma once

#include"clsScreen.h"

class clsShowLoginRegisterScreen: protected clsScreen
{

private:
    static void _printLoginRegisterRecordLine(clsUser::stLoginRegisterRecord loginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << loginRegisterRecord.dateTime;
        cout << "| " << setw(20) << left << loginRegisterRecord.userName;
        cout << "| " << setw(12) << left << loginRegisterRecord.password;
        cout << "| " << setw(10) << left << loginRegisterRecord.permissions;


    }

public:


	static void showLoginRegisterScreen(){

        if (!_checkAcessRights(clsUser::enPermissions::pLoginRegister)) {
            return;
        }

         vector <clsUser::stLoginRegisterRecord> vLoginRegister = clsUser::getLoginRegisterList();
        string Title = "\t  Login Rigister Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegister.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(20) << "username";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegister.size() == 0)
            cout << "\t\t\t\tNo Login/Register Records Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord loginRegisterRecord : vLoginRegister)
            {

                _printLoginRegisterRecordLine(loginRegisterRecord);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}

};

