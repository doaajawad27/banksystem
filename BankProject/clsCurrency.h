#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"clsString.h"
#include<fstream>

using namespace std;

class clsCurrency
{

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1};
	enMode _mode;
	string _country;
	string _CurrencyCode;
	string _CurrencyName;
	float _rate;


	static clsCurrency _convertLineToCurrencyObject(string line) {
		vector<string> vCurrancyRecord = clsString::split(line, "#//#");
		clsCurrency currancyRecord(enMode::UpdateMode, vCurrancyRecord[0], vCurrancyRecord[1], vCurrancyRecord[2], stoi(vCurrancyRecord[3]));
		return currancyRecord;
	}

	static string _convertCurrancyObjectToLine(clsCurrency currancy, string seperator = "#//#") {
		string currancyRecord = "";
		currancyRecord += currancy.getCountry() + seperator;
		currancyRecord += currancy.getCurrencyCode() + seperator;
		currancyRecord += currancy.getCurrencyName() + seperator;
		currancyRecord += to_string(currancy.getRate());
		return currancyRecord;
	}

	static vector<clsCurrency> _loadCurrencysDataFromFile() {
		vector<clsCurrency> vCurrencyData;

		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		
		if (myFile.is_open()) {
			string line;

			while (getline(myFile, line)) {
				vCurrencyData.push_back(_convertLineToCurrencyObject(line));
			}

			myFile.close();
		}
		return vCurrencyData;
	}

	void _saveCurrencyDataToFile(vector<clsCurrency> vCurrancys) {
		fstream myFile;
		myFile.open("Currencies.txt", ios::out);

		if (myFile.is_open()) {
			for (clsCurrency& c : vCurrancys) {
				myFile << _convertCurrancyObjectToLine(c) << endl;
			}

			myFile.close();
		}
	}

	void _update()
	{
		vector<clsCurrency> vCurrencyData = _loadCurrencysDataFromFile();

		for (clsCurrency& c : vCurrencyData) {

			if (getCurrencyCode() == c.getCurrencyCode()) {
				c = *this;
				break;
			}

		}
		
		_saveCurrencyDataToFile(vCurrencyData);      

	}

	static clsCurrency _getEmptyCurrencyObject() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode mode, string country,  string currencyCode, string currencyName, float rate) {
		_mode = mode;
		_country = country;
		_CurrencyName = currencyName;
		_CurrencyCode = currencyCode;
		_rate = rate;
	}

	string getCountry() {
		return _country;
	}
	string getCurrencyName() {
		return _CurrencyName;
	}

	string getCurrencyCode() {
		return _CurrencyCode;
	}

	void updateRate(float newRate) {
		_rate=newRate;
		_update();
	}

	float getRate() {
		return _rate;
	}

	bool isEmpty() {
		return _mode == enMode::EmptyMode;
	}

	static clsCurrency findByCode(string code) {

		code = clsString::upperAllString(code);

		fstream myFile;
		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line)) {
				clsCurrency currency = _convertLineToCurrencyObject(line);
				if (currency.getCurrencyCode() == code) {
					myFile.close();
					return currency;
				}
			}
		}
		return _getEmptyCurrencyObject();
	}

	static clsCurrency findByCountry(string country) {
		country = clsString::upperAllString(country);

		fstream myFile;
		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line)) {
				clsCurrency currency = _convertLineToCurrencyObject(line);
				if ((clsString::upperAllString(currency.getCountry()) ) == country) {
					myFile.close();
					return currency;
				}
			}
		}
		return _getEmptyCurrencyObject();
	}

	static bool isCurrencyExist(string currencyCode) {
		clsCurrency currency = clsCurrency::findByCode(currencyCode);
		return (!currency.isEmpty());
	}

	static vector<clsCurrency> getCurrenciesList() {
		return _loadCurrencysDataFromFile();
	}

};

