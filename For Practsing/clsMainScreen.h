#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsMenueScreen.h"
#include"clsMangeUsersScreen.h"
#include"clsUser.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExhangeScreen.h"



#include <iomanip>


using namespace std;

class clsMainScreen:protected clsScreen
{


    private:
        enum enMainMenueOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eLoginRegister = 8 , eCurrencyExhange =9  ,eExit =10
        };

       static short _ReadMainMenueOption()
        {
            cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 10]? ";
            short Choice = clsInputValidate::ReadShortNumberBetween(1,10,"Enter Number between 1 to 10? ");
            return Choice;
        }

       static  void _GoBackToMainMenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
           
            
            ShowMainMenue();
        }
       
       static void _ShowAllClientsScreen()
       {
//        cout << "\nClient List Screen Will be here...\n";
           clsClientListScreen::ShowTheClientsList();

       }

       static void _ShowAddNewClientsScreen()
       {
//           cout << "\nAdd New Client Screen Will be here...\n";
           clsAddNewClientScreen::ShowAddNewClient();
         
       }

       static void _ShowDeleteClientScreen()
       {
//           cout << "\nDelete Client Screen Will be here...\n";
           clsDeleteClientScreen::ShowDeleteClient();
       }

       static void _ShowUpdateClientScreen()
       {
//           cout << "\nUpdate Client Screen Will be here...\n";
           clsUpdateClientScreen::ShowUpdateClient();

       }

       static void _ShowFindClientScreen()
       {
//           cout << "\nFind Client Screen Will be here...\n";
           clsFindClientScreen::ShowFindScreen();
       }

       static void _ShowTransactionsMenue()
       {
//           cout << "\nTransactions Menue Will be here...\n";
           clsTransctoinsMenueScreen::ShowTransctoinsMenue();
       }

       static void _ShowManageUsersMenue()
       {
//           cout << "\nUsers Menue Will be here...\n";
           clsManageUsersScreen::ShowManageUsersMenue();

       }

    static void _ShowLoginRegisterScreen()
    {
//         cout << "\n LoginRegister Screen ...\n";
       
        clsLoginRegisterScreen::ShowLoginRegister();
    }
    
    
    static void _ShowCurrencyExhangeMainScreen()
    {

        clsCurrnecyScreen::ShowManageCurrencyMenue();
       
    }
    
//       static void _ShowEndScreen()
//           {
//               cout << "\nEnd Screen Will be here...\n";
//
//           }

    
    static void _logOut(){
        CurrentUser=clsUser::Find(" ", " ");
    }
       static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enMainMenueOptions::eListClients:
            {
                
                _ShowAllClientsScreen();
                _GoBackToMainMenue();
                break;
            }
            case enMainMenueOptions::eAddNewClient:
                
               _ShowAddNewClientsScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eDeleteClient:
               
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eUpdateClient:
                
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eFindClient:
               
                _ShowFindClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eShowTransactionsMenue:
                
                _ShowTransactionsMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eManageUsers:
               
                _ShowManageUsersMenue();
                _GoBackToMainMenue();
                break;

                    
                case enMainMenueOptions::eLoginRegister:
                   
                    _ShowLoginRegisterScreen();
                    _GoBackToMainMenue();
                    break;
                    
                case enMainMenueOptions::eCurrencyExhange:
                   
                    _ShowCurrencyExhangeMainScreen();
                    _GoBackToMainMenue();
                    break;
                    
            case enMainMenueOptions::eExit:
               
//                _ShowEndScreen();
                    _logOut();

                break;
            }

        }



	public:
       

       static void ShowMainMenue()
        {
           
           
            _DrawScreenHeader("\t\tMain Screen");

            cout << setw(34) << left <<""<< "===========================================\n";
            cout << setw(34) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(34) << left << "" << "===========================================\n";
            cout << setw(34) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(34) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(34) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(34) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(34) << left << "" << "\t[5] Find Client.\n";
            cout << setw(34) << left << "" << "\t[6] Transactions.\n";
            cout << setw(34) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(34) << left << "" << "\t[8] Login Register.\n";
            cout << setw(34) << left << "" << "\t[9] Currency Exhange.\n";
            cout << setw(34) << left << "" << "\t[10] Logout.\n";
            cout << setw(34) << left << "" << "===========================================\n";
            _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
        }

};

