#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBanckClient.h"
#include"clsInputValidate.h"
#include <iomanip>

class clsAddNewClientScreen:protected clsScreen {
private:
    static void _ReadClientInfo(clsBankClient& Clinet){

       


      
        cout << "Enter FirstName? ";
        Clinet.SetFirstName(clsString::ReadString());

       cout << "Enter LastName? ";
        Clinet.SetLastName(clsString::ReadString());


       cout << "Enter Email? ";
        Clinet.SetEmail(clsString::ReadString());
       
        cout << "Enter PinCode? ";
       Clinet.SetPinCode(clsString::ReadString());

        cout << "Enter phone? ";
       Clinet.SetPhone(clsString::ReadString());
        
       cout << "Enter Account Balance ? ";
       Clinet.SetAccountBalance(clsString::Readfloatnumber());

        
    }
    
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
public:
 
   static  void ShowAddNewClient()
    {
       
       if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
           return ;//this will exit the function and it will not
       }
        
       _DrawScreenHeader("\t Add New Client Screen ");
        string AccountNumber = "";
     
    
        cout << "\nPlease Enter New Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is Alaredy Exist  choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Createed Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

            case clsBankClient::svFaildAccountNumberExists: {
                cout << "\nError account was not saved because account number is used!\n";
                break;
            }
        }
    }
};
