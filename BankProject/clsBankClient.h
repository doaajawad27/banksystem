#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;


    string _accountNumber;
    string _pinCode;
    float _accountBalance;
    bool _markedForDelete = false;



    static clsBankClient _convertLineToClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData = clsString::split(Line, Seperator);

        clsBankClient Client(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], 
            vClientData[3], vClientData[4], vClientData[5],   stod(vClientData[6]));

        return Client;
    }

    
    static string _converClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.firstName + Seperator;
        stClientRecord += Client.lastName + Seperator;
        stClientRecord += Client.email + Seperator;
        stClientRecord += Client.phone + Seperator;
        stClientRecord += Client.getAccountNumber() + Seperator;
        stClientRecord += Client.pinCode + Seperator;
        stClientRecord += to_string(Client.accountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _loadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream myFile;
        myFile.open("Clients.txt", ios::in);//read Mode

        if (myFile.is_open())
        {

            string line;


            while (getline(myFile, line))
            {

                clsBankClient Client = _convertLineToClientObject(line);

                vClients.push_back(Client);
            }

            myFile.close();

        }

        return vClients;

    }

    static void _saveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream myFile;
        myFile.open("Clients.txt", ios::out);//overwrite

        string dataLine;

        if (myFile.is_open())
        {

            for (clsBankClient c : vClients)
            {
                if (c.markedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    dataLine = _converClientObjectToLine(c);
                    myFile << dataLine << endl;

                }

            }

            myFile.close();

        }

    }

    void _update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _loadClientsDataFromFile();

        for (clsBankClient& c : _vClients)
        {
            if (c.getAccountNumber() == getAccountNumber())
            {
                c = *this;
                break;
            }

        }

        _saveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_converClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _accountNumber = AccountNumber;
        _pinCode = PinCode;
        _accountBalance = AccountBalance;

    }

    bool isEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool markedForDeleted()
    {
        return _markedForDelete;
    }

    string getAccountNumber()
    {
        return _accountNumber;
    }

    void setPinCode(string pinCode)
    {
        _pinCode = pinCode;
    }

    string getPinCode()
    {
        return _pinCode;
    }
    __declspec(property(get = getPinCode, put = setPinCode)) string pinCode;

    void setAccountBalance(float accountBalance)
    {
        _accountBalance = accountBalance;
    }

    float getAccountBalance()
    {
        return _accountBalance;
    }
    __declspec(property(get = getAccountBalance, put = setAccountBalance)) float accountBalance;


    static clsBankClient find(string accountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _convertLineToClientObject(Line);
                if (Client.getAccountNumber() == accountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _convertLineToClientObject(Line);
                if (Client.getAccountNumber() == AccountNumber && Client.pinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (isEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {
            _update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient::isClientExist(_accountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }



    }

    static bool isClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::find(AccountNumber);
        return (!Client1.isEmpty());
    }

    bool deleteClient()
    {
        vector <clsBankClient> _vClients;
        _vClients = _loadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.getAccountNumber() == _accountNumber)
            {
                C._markedForDelete = true;
                break;
            }

        }

        _saveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }

    static clsBankClient getAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsBankClient> getClientsList()
    {
        return _loadClientsDataFromFile();
    }

    static float getTotalBalance()
    {
        vector <clsBankClient> vClients = clsBankClient::getClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.accountBalance;
        }

        return TotalBalances;

    }

    void deposit(float amount) {
        _accountBalance += amount;
        save();
    }

    bool withdraw(float amount) {
        if (_accountBalance < amount) {
            return false;
        }
        else {
            _accountBalance -= amount;
            save();
        }
       
    }

    bool transfer(float amount, clsBankClient& destinationClient)
    {
        if (amount > accountBalance) {
            return false;
        }

        withdraw(amount);
        destinationClient.deposit(amount);
        return true;
    }

};

