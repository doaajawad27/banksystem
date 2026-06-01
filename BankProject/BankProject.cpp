#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"

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

//to do
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


int main()
{
	
	//updateClient();
	//addNewCliente();
	deleteClient();
}
