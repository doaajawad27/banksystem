#pragma once
#include<iostream>
#include<string>

using namespace std;

class clsPerson
{
private:
	string _firstName;
	string _lastName;
	string _email;
	string _phone;

public:

	//parametarized constructor
	clsPerson(string firstName, string lastName, string email, string phone) {
		_firstName = firstName;
		_lastName = lastName;
		_email = email;
		_phone = phone;
	}

	//setter and getter property

	void setFirstName(string firstName) {
		_firstName = firstName;
	}
	string getFirstName() {
		return _firstName;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string firstName;

	 
	void setLastName(string lastName) {
		_lastName = lastName;
	}

	string getLastName() {
		return _lastName;
	}

	__declspec(property(get = getLastName, put = setLastName)) string lastName;

	void setEmail(string email) {
		_email = email;
	}

	string getEmail() {
		return _email;
	}

	__declspec(property(get = getEmail, put = setEmail)) string email;

	void setPhone(string phone) {
		_phone = phone;
	}

	string getPhone() {
		return _phone;
	}

	__declspec(property(get = getPhone, put = setPhone)) string phone;

	string fullName() {
		return _firstName + " " + _lastName;
	}

	void print() {
		cout << "\nInfo::";
		cout << "\n--------------------------";
		cout << "\nFirstName   :" << firstName;
		cout << "\nLastName    :" << lastName;
		cout << "\nFullName    :" << fullName();
		cout << "\nEmail       :" << email;
		cout << "\nPhone       :" << phone;
		cout << "\n--------------------------\n";

	}
};

