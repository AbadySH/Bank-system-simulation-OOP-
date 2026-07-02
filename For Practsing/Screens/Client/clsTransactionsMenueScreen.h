
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
#include <iomanip>


using namespace std;

class clsTransctoinsMenueScreen:protected clsScreen
{
private:
    
    enum _enTransctoinsOptions
    {
        eDepsoit = 1,
        eWithdraw = 2,
        eTotalBalances = 3,
        eTransfer = 4,
        eTransferLogRecored = 5,
        enMainMenue = 6
        
    };
    static void _GoBackToTransctoinsMenue()
    {
        string Press;
        cout << "\n\nPress any key to go back to Transctoins Menue...";
        cin>>Press;
        ShowTransctoinsMenue();
    }
    static short _ReadTransctoinsMenueOption()
    {
        cout << "Choose what do you want to do? [1 to 6]? ";
        short Choice = 0;
        cin >> Choice;
        return Choice;
    }
    static void _PerfromTransctoinsMenueOption(_enTransctoinsOptions TransctoinsMenueOption)
    {
        
        switch (_enTransctoinsOptions(TransctoinsMenueOption))
        {
            case eDepsoit:
          
                _ShowDepositScreen();
                _GoBackToTransctoinsMenue();
            break;

            case eWithdraw:
          
                _ShowWethdrawScreen();
                _GoBackToTransctoinsMenue();
            break;

            case eTotalBalances:
            
                _ShowAllClientsBalancesScreen();
                _GoBackToTransctoinsMenue();
            break;

                
            case eTransfer:
            
                _ShowTransferScreen();
                _GoBackToTransctoinsMenue();
            break;

                
            case eTransferLogRecored:
            
                _ShowTransferLogRecoredScreen();
                _GoBackToTransctoinsMenue();
            break;
        case enMainMenue:
           
                _ShowMainMenueScreen();
               
            break;

        }
    }
 
    static void _ShowDepositScreen()
    {
        
        
//        cout << "\t here will be Deposit Clients Screen\n";
      
        clsDepositScreen::ShowDepoistScreen();
    }
    static void _ShowWethdrawScreen()
    {
      
//        cout << "\t here Will be Wethdraw Clients Screen\n";
        clsWithdrawScreen::ShowWithdrawScreen();
        
    }

    static void _ShowAllClientsBalancesScreen()
    {
      
//        cout << "\t here Will be Total Balances Screen\n";
        
        clsTotalBalancesScreen::ShowAClientsBalancesScreen();
    }
    static void _ShowTransferScreen()
    {
      
//        cout << "\t here Will Transfer Screen\n";
        clsTransferScreen::ShowTransferScreen();
        
       
    }
    static void _ShowTransferLogRecoredScreen()
    {
      
//        cout << "\t here Will Transfer Screen\n";
        clsTransferLogScreen::ShowTransferLogScreen();
        
       
    }
    static void _ShowMainMenueScreen()
    {
      
//         "Do nothing here Main screen  will handle  it  ";
        
    }
    public :
    
    static void ShowTransctoinsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {
            return ;//this will exit the function and it will not
        }
         
       
        _DrawScreenHeader("\t\tTransctoins Screen");

        cout << "===========================================\n";
        cout << "\t\tTransctoins Menue Screen\n";
        cout << "===========================================\n";
        cout << "\t[1] Deposit Amount.\n";
        cout << "\t[2] Withdraw Amount.\n";
        cout << "\t[3] Total Balances.\n";
        cout << "\t[4] Transfer Amount.\n";
        cout << "\t[5] Transfer Log .\n";
        cout << "\t[6] Main Menue.\n";
      
        cout << "===========================================\n";

        _PerfromTransctoinsMenueOption((_enTransctoinsOptions)_ReadTransctoinsMenueOption());
    }
};
