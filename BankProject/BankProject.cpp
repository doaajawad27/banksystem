#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

using namespace std;

void readClientInfo(clsBankClient &client) {
	cout << "Enter first name: ";
	client.firstName=clsInputValidate::readString();

	cout << "Enter last name: ";
	client.lastName = clsInputValidate::readString();

	cout << "Enter email: ";
	client.email = clsInputValidate::readString();

	cout << "Enter phone number: ";
	client.phone = clsInputValidate::readString();

	cout << "Enter Pin code: ";
	client.pinCode = clsInputValidate::readString();

	cout << "Enter account balance: ";
	client.accountBalance = clsInputValidate::readDblNumber();
}

void addNewCliente() {
	string accountNumber = "";
	cout << "\nPlease Enter Account Number: ";
	accountNumber = clsInputValidate::readString();
	while (clsBankClient::isClientExist(accountNumber)) {
		cout << "\nAccount Number is already used,please enter another account number? ";
		accountNumber = clsInputValidate::readString();
	}

	clsBankClient newClient = clsBankClient::getAddNewClientObject(accountNumber);
	readClientInfo(newClient);

	clsBankClient::enSaveResults saveResult;
	saveResult = newClient.save();

	switch (saveResult) {
	case clsBankClient::enSaveResults::svSuccedded:
		cout << "\nAccount Added Successfully :-)";
		newClient.print();
		break;
	case clsBankClient::enSaveResults::svFaildEmptyObject:
		cout << "\nAccount was not saved because its empty";
		break;
	case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		cout << "\nAccount was not saved because account number is exist";
	}
}


void deleteClient() {
	string accountNumber = "";
	cout << "\nplease enter account number: ";
	accountNumber = clsInputValidate::readString();

	while (!clsBankClient::isClientExist(accountNumber)) {
		cout << "\nAccount number is not found, please enter another one: ";
		accountNumber = clsInputValidate::readString();
	}
	clsBankClient client = clsBankClient::find(accountNumber);

	client.print();
	char c = 'n';
	cout << "\nAre you sure you want to delete this client? (y/n)?";
	cin >> c;
	if (toupper(c) == 'Y') {
		if (client.deleteClient()) {
			cout << "\nClient deleted successfully :-)\n";
		}
		else
		{
			cout << "Errer!! client was not deleted\n";
		}

	}
	
}

void updateClient() {
	string accountNumber = "";
	cout << "\nplease enter account number: ";
	accountNumber = clsInputValidate::readString();

	while (!clsBankClient::isClientExist(accountNumber)){
		cout << "\nAccount number is not found, please enter another one: ";   
		accountNumber = clsInputValidate::readString();
	}
	clsBankClient client=clsBankClient::find(accountNumber);
	client.print();
	
	cout << "\nRead client info:";
	cout << "\n----------------------\n";



	readClientInfo(client);
	clsBankClient::enSaveResults saveResult;

	saveResult = client.save();

	switch (saveResult) {
	case clsBankClient::enSaveResults::svSuccedded:
		cout << "\nAccount Updated Successfully";
		client.print();
		break;
	case clsBankClient::enSaveResults::svFaildEmptyObject:
		cout << "\nError account was not saved because its empty";
		break;
	}
	

}

void printClientRecordLine(clsBankClient client) {
	cout << "|" << left << setw(15) << client.getAccountNumber();
	cout << "|" << left << setw(20) << client.fullName();
	cout << "|" << left << setw(12) << client.phone;
	cout << "|" << left << setw(20) << client.email;
	cout << "|" << left << setw(10) << client.pinCode;
	cout << "|" << left << setw(12) << client.accountBalance;
}

void printClientRecordBalanceLine(clsBankClient client) {
	cout << "|" << left << setw(15) << client.getAccountNumber();
	cout << "|" << left << setw(20) << client.fullName();
	cout << "|" << left << setw(12) << client.accountBalance;
}

void showClientsList() {
	vector<clsBankClient> vClients = clsBankClient::getClientsList();

	cout << "\n\t\t\t\t\tClient List(" << vClients.size()<<") Client(s)";
	cout << "\n-------------------------------------------------------";
	cout << "------------------------------------------\n" << endl;
	cout << "|" << left << setw(15) << "Account Number";
	cout << "|" << left << setw(20) << "Client Name";
	cout << "|" << left << setw(12) << "Phone";
	cout << "|" << left << setw(20) << "Email";
	cout << "|" << left << setw(10) << "Pin Code";
	cout << "|" << left << setw(12) << "Balance";
	cout << "\n-------------------------------------------------------";
	cout << "------------------------------------------\n" << endl;

	for (clsBankClient& c : vClients) {
		printClientRecordLine(c);
		cout << endl;
	}

	cout << "\n-------------------------------------------------------";
	cout << "------------------------------------------\n" << endl;
}

void showTotalBalances() {
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
			printClientRecordBalanceLine(c);
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
	
	//updateClient();
	//addNewCliente();
	//deleteClient();
	//showClientsList();   

	showTotalBalances();
}
