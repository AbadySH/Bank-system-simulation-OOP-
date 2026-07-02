#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsUpdateCurrencyRateScreen :protected clsScreen

{
private:


   
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

public:

    static void ShowUpdateCurrencyRateScreen()
    {
        
        _DrawScreenHeader("\tUpdate Currency  Rate Screen");
        
        string Rate = "";
        
        cout << "\nPlease Enter Courrency  Code : ";
        Rate = clsInputValidate::ReadString();
        
        while (!clsCurrency::IsCurrencyExist(Rate))
        {
            cout << "\nCurrency Code is not found, choose another one: ";
            Rate = clsInputValidate::ReadString();
           
        }
        
        clsCurrency Currency = clsCurrency::FindByCode(Rate);
        
        _PrintCurrency(Currency);
    
      
        cout << "\nAre you sure you want to update this Rate  y/n? ";
        
        char Answer = 'n';
        cin >> Answer;
        
        if (Answer == 'y' || Answer == 'Y')
        {
            float code  =0;
           
            
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";
            cout << "\nEntr New Rate  ? ";
            cin>>code;
            Currency.UpdateRate(code);
            
            cout << "\nnCurrency Rate  Updated Successfully :-)\n";
            _PrintCurrency(Currency);
            
        
        }
    }
    
    };
