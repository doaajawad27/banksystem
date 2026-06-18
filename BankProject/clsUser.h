#pragma once

#include"clsPerson.h"
#include<iostream>
#include<string>
#include<vector>
#include"clsString.h"
#include<fstream>

class clsUser:public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1,AddNewMode = 2};
	enMode _mode;
	string _username;
	string _password;
	int _permissions;

	bool _markForDelete = false;

	static clsUser _convertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

	}

	static string _converUserObjectToLine(clsUser user, string seperator = "#//#")
	{

		string userRecord = "";
		userRecord += user.firstName + seperator;
		userRecord += user.lastName + seperator;
		userRecord += user.email + seperator;
		userRecord += user.phone + seperator;
		userRecord += user.username + seperator;
		userRecord += user.password + seperator;
		userRecord += to_string(user.permissions);

		return userRecord;

	}

	static clsUser _getEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static void _saveUsersDataToFile() {

	}

	void _addDataLineToFile(string line) {
		fstream myfile;
		myfile.open("Users.txt", ios::out | ios::app);

		if (myfile.is_open())
		{
			myfile << line << endl;
			myfile.close();
		}
	}

	void _addNew() {

		_addDataLineToFile(_converUserObjectToLine(*this));

	}

	void _update() {

		vector<clsUser> vUsers = _loadUsersDataFromFile();
		
		for (clsUser &u:vUsers)
		{

			if (u.username == _username) {
				u = *this;
				break;
			}
		}
		_saveUsersDataToFile(vUsers);
	}

	static vector<clsUser> _loadUsersDataFromFile() {
		
		vector<clsUser> vUsers;
		fstream myfile;
		
		myfile.open("Users.txt", ios::in);

		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {
				clsUser user = _convertLinetoUserObject(line);
				vUsers.push_back(user);
			}
			myfile.close();
		}
		return vUsers;
	}

	void _saveUsersDataToFile(vector<clsUser>_vUsers) {
		fstream file;
		file.open("Users.txt", ios::out);
		if (file.is_open()) {
			for (clsUser& u : _vUsers) {
				if (u._markedForDelete()==false) {
					file << _converUserObjectToLine(u) << endl;
				}
			}
			file.close();
		}
	}

public:

	enum enPermissions{eAll=-1,pListClients=1,pAddNewClient=2,pDeleteClient=4,pUpdateClient=8,pFindClient=16
		,pTransactions=32,pManageUSers=64};


	clsUser(enMode mode, string firstName, string lastName,
		string email, string phone, string username, string password,
		int permissions) :clsPerson(firstName, lastName, email, phone) {
		_mode = mode;
		_username = username;
		_password = password;
		_permissions = permissions;
	}

	bool  checkUserPermissions(enPermissions permissions) {
		if (this->permissions == enPermissions::eAll || (this->permissions & permissions) == permissions)
			return true;
		else
			return false;
	}

	bool isEmpty() {
		return _mode == enMode::EmptyMode;
	}

	bool _markedForDelete() {
		return _markForDelete;
	}
 
	string getUsername() {
		return _username;
	}

	void setUsername(string username) {
		_username = username;
	}

	__declspec(property(get = getUsername, put = setUsername)) string username;

	string getPassword() {
		return _password;
	}

	void setPassword(string password) {
		_password = password;
	}

	__declspec(property(get = getPassword, put = setPassword)) string password;

	int getPermissions() {
		return _permissions;
	}

	void setPermissions(int permissions) {
		_permissions = permissions;
	}

	__declspec(property(get = getPermissions, put = setPermissions)) int permissions;

	static clsUser find(string username) {

		fstream myFile;
		myFile.open("Users.txt", ios::in);//read mode

		if (myFile.is_open()) {

			string line;
			while (getline(myFile, line)) {
				clsUser user = _convertLinetoUserObject(line);

				if (username == user.username) {
					myFile.close();
					return user;
				}

			}
			myFile.close();
			return _getEmptyUserObject();
		}
	}

	static clsUser find(string username,string password) {

		fstream myFile;
		myFile.open("Users.txt", ios::in);//read mode

		if (myFile.is_open()) {

			string line;
			while (getline(myFile, line)) {
			clsUser user = _convertLinetoUserObject(line);

				if (username == user.username && password==user.password) {
					myFile.close();
					return user;
				}

			}
			myFile.close();
			return _getEmptyUserObject();
		}
	}
	
	enum enSaveResults {svFaildEmptyObject=0,svSucceeded=1,svFaildUserExicts=2};

	enSaveResults save() {
		switch (_mode) {
		case enMode::AddNewMode:
			if (clsUser::isUserExist(_username)) {
				return enSaveResults::svFaildUserExicts;
			}
			else {
				_addNew();
				_mode=enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;

		case enMode::UpdateMode:
			_update();
			return enSaveResults::svSucceeded;
			break;

		case enMode::EmptyMode:
			if (isEmpty()) {
				return enSaveResults::svFaildEmptyObject;
				break;
			}
		}
	}

	static bool isUserExist(string username) {
		clsUser user = clsUser::find(username);
		return(!user.isEmpty());
	}


	bool deleteUser()
	{
		vector <clsUser> _vUsers;
		_vUsers = _loadUsersDataFromFile();

		for (clsUser& u : _vUsers)
		{
			if (u.username == username)
			{
				u._markForDelete = true;
				break;
			}

		}

		_saveUsersDataToFile(_vUsers);

		*this = _getEmptyUserObject();

		return true;

	}


	static clsUser getAddNewUserObject(string userName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", userName, "", 0);
	}

	static vector <clsUser> getUsersList()
	{
		return _loadUsersDataFromFile();
	}

};

