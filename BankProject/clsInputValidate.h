#pragma once
#include<iostream>
#include"clsDate.h"

using namespace std;

class clsInputValidate
{
public:

	static bool isNumberBetween(short num, short from, short to) {
		return (num >= from && num <= to);
	}

	static bool isNumberBetween(int num, int from, int to) {
		return (num >= from && num <= to);
	}

	static bool isNumberBetween(float num, float from, float to) {
		return (num >= from && num <= to);
	}

	static bool isNumberBetween(double num, double from, double to) {
		return (num >= from && num <= to);
	}

	static bool isDateBetween(clsDate date, clsDate dateFrom, clsDate dateTo) {
		//Date>=From && Date<=To
		if ((clsDate::isDate1AfterDate2(date, dateFrom) || clsDate::isDate1EqualDate2(date, dateFrom))
			&&
			(clsDate::isDate1BeforeDate2(date, dateTo) || clsDate::isDate1EqualDate2(date, dateTo))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::isDate1AfterDate2(date, dateTo) || clsDate::isDate1EqualDate2(date, dateTo))
			&&
			(clsDate::isDate1BeforeDate2(date, dateFrom) || clsDate::isDate1EqualDate2(date, dateFrom))
			)
		{
			return true;
		}

		return false;

	}

	static int readIntNumber(string errorMessage = "Invalid number, Please enter a valid integer.") {
		int number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage << endl;
		}
		return number;
	}

	static int readIntNumberInBetween(int from, int to, string errorMessage = "Number is not within range, Enter again:\n") {
		int number;
		number = readIntNumber();
		while (!isNumberBetween(number, from, to)) {
			cout << errorMessage << endl;
			number = readIntNumber();
		}
		return number;
	}

	static int readShortNumberInBetween(short from, short to, string errorMessage = "Number is not within range, Enter again:\n") {
		short number;
		number = readIntNumber();
		while (!isNumberBetween(number, from, to)) {
			cout << errorMessage << endl;
			number = readIntNumber();
		}
		return number;
	}


	static float readFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	//static float readFloatNumberBetween(double from, double to, string ErrorMessage = "Number is not within range, Enter again:\n")
	//{
	//	float number = readFloatNumber();

	//	while (!isNumberBetween(number, from, to)) {
	//		cout << errorMessage << endl;
	//		number = readFloatNumber();
	//	}
	//	return number;
	//}

	static double readDblNumber(string errorMessage = "Invalid number, please enter a valid double number.") {
		double number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage << endl;
		}
		return number;
	}

	static double readDblNumberInBetween(double from, double to, string errorMessage = "Number is not within range, Enter again:\n") {
		double number;
		number = readDblNumber();
		while (!isNumberBetween(number, from, to)) {
			cout << errorMessage << endl;
			number = readDblNumber();
		}
		return number;
	}

	static string readString(string errorMessage = "Invalid input, please enter a valid string.") {
		string str;
		getline(cin >> ws, str);
		while (str.empty()) {
			cout << errorMessage << endl;
			getline(cin >> ws, str);
		}
		return str;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

};

