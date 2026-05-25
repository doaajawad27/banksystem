#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include<string>

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode{emptyMode=0,updateMode=1};
	enMode _mode;

	string _accountNumber;
	string _pinCode;
	float _accountBalance;

	static clsBankClient _convertLineToClientObject(string line, string sep = "#//#") {
		vector<string> vClientRecord = clsString::split(line, sep);
		return clsBankClient(enMode::updateMode,vClientRecord[0],vClientRecord[1],vClientRecord[2],vClientRecord[3],vClientRecord[4],vClientRecord[5],stof(vClientRecord[6]));
	}

	static clsBankClient _getEmptyClientObject() {
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}

public:
	clsBankClient(enMode mode,string firstName, string lastName, string email, string phone,string accountNumber,string pinCode,float accountBalance):
		clsPerson(firstName, lastName, email, phone)
	{
		_mode = mode;
		_accountNumber = accountNumber;
		_pinCode = pinCode;
		_accountBalance = accountBalance;
	}

	bool isEmpty() {
		return _mode == enMode::emptyMode;
	}

	string getAccountNumber() {
		return _accountNumber; 
	}


	void setPinCode(string pinCode) {
		_pinCode = pinCode;
	}

	string getPinCode() {
		return _pinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string pinCode;

	void setAccountBalance(float accountBalance) {
		_accountBalance = accountBalance;
	}

	float getAccountBalance() {
		return _accountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) float accountBalance;


	void print() {
		cout << "\nClient Card:";
		cout << "\n--------------------------";
		cout << "\nFirstName   :" << firstName;
		cout << "\nLastName    :" << lastName;
		cout << "\nFullName    :"<<fullName();
		cout << "\nEmail       :"<<email;
		cout << "\nPhone       :" << phone;
		cout << "\nAccount No. :" << _accountNumber;
		cout << "\nPin Code    :" << _pinCode;
		cout << "\nAccount Bal. :" << _accountBalance;
		cout << "\n--------------------------\n";

	}

	static clsBankClient find(string accountNumber) {

		fstream myFile;
		myFile.open("clients.txt", ios::in);

		if (myFile.is_open()) {
			string line;
			while (getline(myFile,line)) {
				clsBankClient client = _convertLineToClientObject(line);
				if (client.getAccountNumber() == accountNumber) {
					myFile.close();
					return client;
				}

			}

			myFile.close();
		}
		return _getEmptyClientObject();
	}

	static clsBankClient find(string accountNumber,string pinCode) {

		fstream myFile;
		myFile.open("clients.txt", ios::in);

		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsBankClient client = _convertLineToClientObject(line);
				if (client.getAccountNumber() == accountNumber && client.getPinCode()==pinCode) {
					myFile.close();
					return client;
				}
			}

			myFile.close();
		}
		return _getEmptyClientObject();
	}

	static bool isClientExist(string accountNumber) {
		clsBankClient client1 = clsBankClient::find(accountNumber);
		return (!client1.isEmpty());
	}

};

