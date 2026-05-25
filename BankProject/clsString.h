#pragma once
#include<iostream>
#include<vector>
using namespace std;
class clsString
{
private:

	string _value;



public:

	clsString() {
		_value = "";
	}

	clsString(string value) {
		_value = value;
	}

	void setValue(string value) {
		_value = value;
	}

	string getValue() {
		return _value;
	}

	__declspec(property(get = getValue, put = setValue)) string Value;

	static bool isVowel(char c) {
		char lowerC = tolower(c);
		return lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u';
	}

	static char invertLetterCase(char c) {
		return isupper(c) ? tolower(c) : toupper(c);
	}

	static void printFirstLetterOfEachWord(string str) {
		bool isFirstLetterInWord = true;
		for (int i = 0;i < str.length();i++) {
			if (isFirstLetterInWord && str[i] != ' ')
			{
				cout << str[i] << " ";
			}
			isFirstLetterInWord = str[i] == ' ' ? true : false;
		}
		cout << endl;
	}
	void printFirstLetterOfEachWord() {
		printFirstLetterOfEachWord(_value);
	}

	static string upperFirstLetterOfEachWord(string str)
	{
		bool isFirstLetterInWord = true;
		for (int i = 0;i < str.length();i++) {
			if (isFirstLetterInWord && str[i] != ' ')
			{
				str[i] = toupper(str[i]);
			}
			isFirstLetterInWord = str[i] == ' ' ? true : false;
		}
		return str;
	}
	void upperFirstLetterOfEachWord()
	{
		_value = upperFirstLetterOfEachWord(_value);
	}

	static string lowerFirstLetterOfEachWord(string str)
	{
		bool isFirstLetterInWord = true;
		for (int i = 0;i < str.length();i++) {
			if (isFirstLetterInWord && str[i] != ' ')
			{
				str[i] = tolower(str[i]);
			}
			isFirstLetterInWord = str[i] == ' ' ? true : false;
		}
		return str;
	}
	void lowerFirstLetterOfEachWord()
	{
		_value = lowerFirstLetterOfEachWord(_value);
	}

	static string upperAllString(string str) {

		for (int i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
		return str;
	}
	void upperAllString() {
		_value = upperAllString(_value);
	}

	static string lowerAllString(string str) {

		for (int i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}
		return str;
	}
	void lowerAllString() {
		_value = lowerAllString(_value);
	}

	static string invertAllStringLetterCase(string str) {
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = invertLetterCase(str[i]);
		}
		return str;
	}
	void invertAllStringLetterCase() {
		_value = invertAllStringLetterCase(_value);
	}


	static short countCapitalLetter(string str) {
		short count = 0;

		for (int i = 0;i < str.length();i++) {
			if (isupper(str[i])) {
				count++;
			}
		}
		return count;
	}
	short countCapitalLetter() {
		return countCapitalLetter(_value);
	}

	static short countLowerLetter(string str) {
		short count = 0;

		for (int i = 0;i < str.length();i++) {
			if (islower(str[i])) {
				count++;
			}
		}
		return count;
	}
	short countLowerLetter() {
		return countLowerLetter(_value);
	}

	static short countVowels(string str) {
		short count = 0;
		for (int i = 0;i < str.length();i++) {
			if (isVowel(str[i])) {
				count++;
			}
		}
		return count;
	}
	short countVowels() {
		return countVowels(_value);
	}

	static void printVowels(string str) {
		for (short i = 0; i < str.length(); i++)
		{
			if (isVowel(str[i]))
			{
				cout << str[i] << " ";
			}

		}
		cout << endl;
	}
	void printVowels() {
		printVowels(_value);
	}

	static void  printEachWordInString(string str) {
		string word = "";
		short pos = 0;
		string delm = " ";

		while ((pos = str.find(delm)) != string::npos) {
			word = str.substr(0, pos);
			if (word != "")
			{
				cout << word << endl;
			}
			str.erase(0, pos + delm.length());
		}
		if (str != "") {
			cout << str << endl;
		}
	}
	void printEachWordInString() {
		printEachWordInString(_value);
	}

	static short countEachWordInString(string str) {
		string word = "";
		short pos = 0;
		string delm = " ";
		short count = 0;
		while ((pos = str.find(delm)) != string::npos) {
			word = str.substr(0, pos);
			if (word != "")
			{
				count++;
			}
			str.erase(0, pos + delm.length());
		}
		if (str != "") {
			count++;
		}
		return count;
	}
	short countEachWordInString() {
		return countEachWordInString(_value);
	}

	static vector<string> split(string str, string delm) {
		string word = "";
		short pos = 0;
		vector<string> vWords;

		if (delm.empty()) {
			vWords.push_back(str);
			return vWords;
		}

		while ((pos = str.find(delm)) != string::npos) {
			word = str.substr(0, pos);
			vWords.push_back(word);
			str.erase(0, pos + delm.length());
		}
		if (str != "") {
			vWords.push_back(word);
		}
		return vWords;
	}
	vector<string> split() {
		return split(_value, " ");
	}

	static string trimLeft(string str) {
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ') {
				return str.substr(i, str.length() - i);
			}
		}
	}
	void  trimLeft() {
		_value = trimLeft(_value);
	}

	static string trimRigth(string str) {
		for (short i = str.length() - 1; i >= 0; i--)
		{
			if (str[i] != ' ') {
				return str.substr(0, i + 1);
			}
		}
	}
	string trimRigth() {
		trimRigth(_value);
	}

	static string trim(string str) {
		return trimLeft(trimRigth(str));
	}
	string trim() {
		return trim();
	}

	static string joinString(vector<string> vString, string separator) {
		string s;
		for (string& n : vString) {
			s += n + separator;
		}
		s.substr(0, s.length() - separator.length());
	}

	static string joinString(string arr[100], short len, string separator) {
		string s;
		for (short i = 0;i < len;i++) {
			s += arr[i] + separator;
		}
		s.substr(0, s.length() - separator.length());
	}

	static string  reverseWordInString(string str) {
		vector<string> vString = split(str, " ");
		str = "";
		vector<string>::iterator iter = vString.end();
		while (iter != vString.begin()) {
			str += *iter + " ";
		}
		return str.substr(0, str.length() - 1);
	}
	string reverseWordInString() {
		return reverseWordInString(_value);
	}

	static string replaceWordsInString(string str, string sToReplace, string sReplaceTo) {
		short pos = str.find(sToReplace);
		while (pos != string::npos) {
			str = str.replace(pos, sToReplace.length(), sReplaceTo);
			pos = str.find(sToReplace);
		}
		return str;
	}

	static string removePunctuationsFromString(string str) {
		string s2 = "";
		for (short i = 0; i < str.length(); i++)
		{
			if (!ispunct(str[i])) {
				s2 += str[i];
			}
		}
		return s2;
	}
	string removePunctuationsFromString() {
		removePunctuationsFromString(_value);
	}


	static short countSpecificLetter(string str, char letter, bool machCase = true) {
		short count = 0;

		for (short i = 0; i < str.length(); i++)
		{
			if (machCase) {
				if (str[i] == letter)
					count++;
			}
			else {
				if (tolower(str[i]) == tolower(letter))
					count++;
			}
		}

		return count;
	}


};

