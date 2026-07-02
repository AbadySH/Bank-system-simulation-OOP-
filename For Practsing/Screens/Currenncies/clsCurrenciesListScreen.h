#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsUser.h"
#include <iomanip>

class clsCurrenciesListScreen : protected clsScreen {
    private :
   static void _PrintCurrencyRecordLine(clsCurrency Currency) {
       
          

        cout << "| " << setw(35) << left <<Currency.Country()  ;
        cout << "| " << setw(10) << left << Currency.CurrencyCode();
        cout << "| " << setw(35) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
        

       

    }
public:
    
  static void ShwoTheCurrenciesList() {
        
     
       
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();
      string Title ="\t Currency Screen ";
      string SubTitle= "\n\t\t\t\t\tCurrency List (" + to_string(vCurrency.size()) +") Currencies." ;
      
      _DrawScreenHeader(Title,SubTitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

      cout << "| " << left << setw(35) << "Country";
      cout << "| " << left << setw(10) << "code";
      cout << "| " << left << setw(35) << "Name";
      cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else

            for (clsCurrency& Currency : vCurrency)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

