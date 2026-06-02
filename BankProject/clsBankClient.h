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

	enum enMode{emptyMode=0,updateMode=1,addNewMode=2};
	enMode _mode;

	string _accountNumber;
	string _pinCode;
	float _accountBalance;
	bool _MarkForDelete=false;

	static clsBankClient _convertLineToClientObject(string line, string sep = "#//#") {
		vector<string> vClientRecord = clsString::split(line, sep);
		return clsBankClient(enMode::updateMode,vClientRecord[0],vClientRecord[1],vClientRecord[2],vClientRecord[3],vClientRecord[4],vClientRecord[5],stof(vClientRecord[6]));
	}

	
	static string _convertClientObjectToLine(clsBankClient client, string sep = "#//#") {

		return client.firstName + sep + client.lastName + sep
			+ client.email + sep + client.phone + sep
			+ client.getAccountNumber() + sep + client.pinCode + sep
			+ to_string(client.accountBalance);
	}

	static clsBankClient _getEmptyClientObject() {
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _loadClientsDataFromFile() {
		vector<clsBankClient> vClients;
		fstream file;
		file.open("Clients.txt", ios::in);

		if (file.is_open()) {

			string line;

			while (getline(file, line)) {
				clsBankClient client = _convertLineToClientObject(line);
				vClients.push_back(client);
			}
			file.close();
		}
		return vClients;
	}

	static void _saveClientsDataToFile(vector<clsBankClient>& vClients) {
		fstream file;
		file.open("Clients.txt", ios::out);

		string dataLine;
		if (file.is_open())
		{
			for (clsBankClient& c : vClients)
			{
				if (!c._MarkForDelete) {
					dataLine = _convertClientObjectToLine(c);
					file << dataLine << endl;
				}	
			}
			file.close();
		}
	}

	void _addDataLineToFile(string clientDataLine) {
		fstream file;
		file.open("Clients.txt", ios::out | ios::app);

		if (file.is_open())
		{
			file << clientDataLine << endl;
			file.close();
		}
	}

	void _addNew() {
		_addDataLineToFile(_convertClientObjectToLine(*this));
	}


	void _update() {
		vector <clsBankClient> _vClients;
		_vClients = _loadClientsDataFromFile();
			
		for (clsBankClient& c:_vClients)
		{
			if (c.getAccountNumber()==getAccountNumber())
			{
				c = *this;
				break;
			}
		}

		_saveClientsDataToFile(_vClients);

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

	static clsBankClient getAddNewClientObject(string accountNumber) {
		return clsBankClient(enMode::addNewMode, "", "", "", "", accountNumber, "", 0);
	}

	enum enSaveResults{svFaildEmptyObject=0,svSuccedded=1, svFaildAccountNumberExists=2};

	enSaveResults save() {
		switch (_mode) {
		case enMode::emptyMode:
			return enSaveResults::svFaildEmptyObject;
		case enMode::updateMode:
			_update();
			return enSaveResults::svSuccedded;
			break;
		case enMode::addNewMode:
			if (clsBankClient::isClientExist(_accountNumber)) {
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_addNew();
				_mode = enMode::updateMode;
				return enSaveResults::svSuccedded;
			}
		}
	}

	bool deleteClient() {

		vector<clsBankClient> _vClients = _loadClientsDataFromFile();


		for (clsBankClient& c : _vClients)
		{
			if (c.getAccountNumber() == _accountNumber)		
			{
					c._MarkForDelete=true;
					break;
			}
		}
		
		_saveClientsDataToFile(_vClients);
		*this = _getEmptyClientObject();
		return true;
	}

	static vector<clsBankClient> getClientsList() {
		return _loadClientsDataFromFile();
	}

};

