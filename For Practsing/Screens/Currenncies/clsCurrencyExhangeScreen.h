#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clscurrencyCalculatorScreen.h"
#include <iomanip>



class clsCurrnecyScreen :protected clsScreen
{

private:
    enum enManageCurrencyMenueOptions {
        eListCurrencies = 1, eFindCurrency= 2, eUpdateRate = 3,
        eCurrencyCalculator = 4 ,enMainMenue =5
    };

    static short ReadManageCurrencyMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageCurrencyMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
       
        ShowManageCurrencyMenue();
    }

    static void _ShowListCurrenciesScreen()
    {
//        cout << "\nList Currencies Screen Will Be Here.\n";
        clsCurrenciesListScreen::ShwoTheCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
//        cout << "\nFind Currency Screen Will Be Here.\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
//        cout << "\nUpdate Rate Screen Will Be Here.\n";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
//        cout << "\nCurrency Calculator Screen Will Be Here.\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
        
    }


    static void _PerformManageCurrencyMenueOption(enManageCurrencyMenueOptions ManageCurrencyMenueOptions)
    {

        switch (ManageCurrencyMenueOptions)
        {
            case enManageCurrencyMenueOptions::eListCurrencies:
        {
            
            _ShowListCurrenciesScreen();
            _GoBackToManageCurrencyMenue();
            break;
        }

        case enManageCurrencyMenueOptions::eFindCurrency:
        {
            
            _ShowFindCurrencyScreen();
            _GoBackToManageCurrencyMenue();
            break;
        }

        case enManageCurrencyMenueOptions::eUpdateRate:
        {
            
            _ShowUpdateRateScreen();
            _GoBackToManageCurrencyMenue();
            break;
        }

        case enManageCurrencyMenueOptions::eCurrencyCalculator:
        {
           
            _ShowCurrencyCalculatorScreen();
            _GoBackToManageCurrencyMenue();
            break;
        }


        case enManageCurrencyMenueOptions::enMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }



public:


    static void ShowManageCurrencyMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrency)) {
            return ;//this will exit the function and it will not
        }
         
      
        _DrawScreenHeader("\t Manage Currency Main  Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Currency Main Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator .\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageCurrencyMenueOption((enManageCurrencyMenueOptions)ReadManageCurrencyMenueOption());
    }

};

