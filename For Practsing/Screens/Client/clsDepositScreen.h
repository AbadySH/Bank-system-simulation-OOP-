#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBanckClient.h"
#include <iomanip>
class clsDepositScreen: protected clsScreen{
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
     static void  ShowDepoistScreen(){
       
         _DrawScreenHeader("\t Depoist  Screen \n");
       string AccountNumber= _ReadAccountNumber() ;
        
    
         while (!clsBankClient::IsClientExist(AccountNumber))
         {
             cout << "\nAccount number is not found, choose another one: ";
             AccountNumber = clsInputValidate::ReadString();
         }
         clsBankClient Client1 = clsBankClient::Find(AccountNumber);
         _PrintClient(Client1);
         cout<<"Please Enter the Number You Want To Depoist :"<<endl;
         double Amount =0;
         Amount= clsInputValidate::ReadDblNumber();
         char Answer = 'n';
         cout << "\n\nAre you Sure You want perfrom This Transctoin ? ";
         cin>>Answer;
         if (Answer == 'y'||Answer == 'Y') {
        
             Client1.Deposit(Amount);
             cout << "\n done  Successfully,New Balance Is :"<<Client1.GetAccountBalance();
             
         }
         else
             {
                 cout << "\nOperation was cancelled.\n";
             }
        
        
     
            
                
                    
                   

                
                
               
                

               
        
        
       
      
    }
    
};
