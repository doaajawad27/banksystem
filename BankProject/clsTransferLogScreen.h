#pragma once
#include"clsScreen.h"

class clsTransferLogScreen:clsScreen
{

private:
    static void _printTransferLogRecord(clsBankClient::stTransferLog &transferLogRecord) {
    
        cout << setw(8) << left << "" << "| " << left << setw(20) << transferLogRecord.dateTime;
        cout << "| " << left << setw(10) << transferLogRecord.sAccountNum;
        cout << "| " << left << setw(10) << transferLogRecord.dAccountNum;
        cout << "| " << left << setw(12) << transferLogRecord.amount;
        cout << "|" << left << setw(12) << transferLogRecord.sBalance;
        cout << "|" << left << setw(12) << transferLogRecord.dBalance;
        cout << "|" << left << setw(15) << transferLogRecord.username;

    }
public:

	static void showTransferLogScreen() {
		_DrawScreenHeader("\tTransfer Log");

        //if (!_checkAcessRights(clsUser::enPermissions::pLoginRegister)) {
        //    return;
        //}

        vector <clsBankClient::stTransferLog> vTransferList = clsBankClient::getTransferLogList();
   
      
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(12) << "Amount";
        cout << "|" << left << setw(12) << "s.Balance";
        cout << "|" << left << setw(12) << "d.Balance";
        cout << "|" << left << setw(15) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferList.size() == 0)
            cout << "\t\t\t\tNo Transfer Records Available In the System!";
        else

            for (clsBankClient::stTransferLog transferlog : vTransferList)
            {

                _printTransferLogRecord(transferlog);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

};

