#pragma once

#include"clsCurrency.h"
#include<iomanip>
#include<iostream>
#include<vector>
#include"clsScreen.h"

using namespace std;

class clsCurrenciesListScreen:protected clsScreen
{

    static void _printCurrenciesRecordLine(clsCurrency currency)
    {

        cout << setw(8) << left << "" << "| " << setw(28) << left << currency.getCountry();
        cout << "| " << setw(10) << left << currency.getCurrencyCode();
        cout << "| " << setw(40) << left << currency.getCurrencyName();
        cout << "| " << setw(15) << left << currency.getRate();
      
    }

       

public:

    static void showCurrenciesListScreen() {

        //if (!_checkAcessRights(clsUser::enPermissions::pListClients)) {
       //    return;
       //}

        vector <clsCurrency> vCurrencies = clsCurrency::getCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(28) << " Country";
        cout << "| " << left << setw(10) << " Code";
        cout << "| " << left << setw(40) << " Name";
        cout << "| " << left << setw(15) << "Rate/(1$)";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencies.size() == 0) {
            cout << "\t\t\t\tNo Currencies Available In the System!";
        }
        else {

          for(clsCurrency &c:vCurrencies) 
          {
              _printCurrenciesRecordLine(c);
              cout << endl;

          }

        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

