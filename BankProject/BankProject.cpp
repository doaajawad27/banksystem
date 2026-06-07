#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsMainScreen.h"

using namespace std;





void _printClientRecordBalanceLine(clsBankClient client) {
	cout << "|" << left << setw(15) << client.getAccountNumber();
	cout << "|" << left << setw(20) << client.fullName();
	cout << "|" << left << setw(12) << client.accountBalance;
}
static void _showTotalBalances() {
	vector<clsBankClient> vClients = clsBankClient::getClientsList();

	cout << "\n\t\t\t\t\Balances List(" << vClients.size() << ") Client(s)";
	cout << "\n-------------------------------------------------------";
	cout << "------------------------------------------\n" << endl;
	cout << "|" << left << setw(15) << "Account Number";
	cout << "|" << left << setw(20) << "Client Name";
	cout << "|" << left << setw(12) << "Balance";
	cout << "\n-------------------------------------------------------";
	cout << "------------------------------------------\n" << endl;

	double totalBalances = clsBankClient::getTotalBalance();

	if (vClients.size() == 0) {
		cout << "\t\t\tNo Clients avilable in the system!";
	}
	else {
		for (clsBankClient& c : vClients) {
			_printClientRecordBalanceLine(c);
			cout << endl;
		}
	}

	cout << "\t\t\t\t  Total Balances = " << totalBalances << endl;
	cout << "\t\t\t\t ( " << clsUtil::NumberToText(totalBalances) << endl;

	cout << "\n-------------------------------------------------------";
	cout << "------------------------------------------\n" << endl;

}





int main()
{
	clsMainScreen::showMainMenu();

}
