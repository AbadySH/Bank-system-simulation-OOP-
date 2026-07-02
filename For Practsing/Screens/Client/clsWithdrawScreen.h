#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBanckClient.h"
#include <iomanip>
class clsWithdrawScreen: protected clsScreen{
private:
    static void _PrintClient (clsBankClient& Clinet)
      {
    
        cout << "\t Client Card Info :\n";
          cout << "\n___________________";
  
        cout << "\nFirstName : " << Clinet.GetFirstName() ;  // ✅ use getter
          cout << "\nLastName  : " << Clinet.GetLastName();     // ✅ use getter
          cout << "\nFull Name : " << Clinet.FullName();
          cout << "\nEmail     : " << Clinet.GetEmail();        // ✅ use getter
          cout << "\nPhone     : " << Clinet.GetPhone();        // ✅ use getter
  
          cout << "\nAccountNumber : " << Clinet.AccountNumber();
          cout << "\nPassWord      : " << Clinet.GetPinCode();
        cout << "\nBalance       : " << Clinet.GetAccountBalance();
  
          cout << "\n___________________\n";
      }
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }
    
    
    
public:
     static void  ShowWithdrawScreen(){
       
         _DrawScreenHeader("\t   Withdraw Screen");

         string AccountNumber = _ReadAccountNumber();


         while (!clsBankClient::IsClientExist(AccountNumber))
         {
             cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
             AccountNumber = _ReadAccountNumber();
         }

         clsBankClient Client1 = clsBankClient::Find(AccountNumber);
         _PrintClient(Client1);


         double Amount = 0;
         cout << "\nPlease enter Withdraw amount? ";
         Amount = clsInputValidate::ReadDblNumber();

         cout << "\nAre you sure you want to perform this transaction? ";
         char Answer = 'n';
         cin >> Answer;

         if (Answer == 'Y' || Answer == 'y')
         {
            if( Amount<=Client1.GetAccountBalance())
            {
                Client1.Withdraw(Amount);
             cout << "\nAmount Withdrew Successfully.\n";
             cout << "\nNew Balance Is: " << Client1.GetAccountBalance();
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.GetAccountBalance();
                
            }
         }
         else
         {
             cout << "\nOperation was cancelled.\n";
         }

     }

    
};
