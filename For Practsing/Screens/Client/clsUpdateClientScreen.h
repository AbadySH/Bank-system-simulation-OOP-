
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBanckClient.h"

#include <iomanip>

class clsUpdateClientScreen : protected clsScreen {
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
public:
    static void ShowUpdateClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients)) {
            return ;//this will exit the function and it will not
        }
         
        string Title ="\t Update Client Screen ";
        _DrawScreenHeader(Title);
        
        string AccountNumber = "";
        
        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        char Delete ='n';
        cin >> Delete;
        if (Delete=='Y'||Delete=='y'){
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";
            
            _ReadClientInfo(Client1);
            
            clsBankClient::enSaveResults SaveResult;
            
            SaveResult = Client1.Save();
            
            switch (SaveResult)
            {
                case  clsBankClient::enSaveResults::svSucceeded:
                {
                    cout << "\nAccount Updated Successfully :-)\n";
                    Client1.Print();
                    break;
                }
                case clsBankClient::enSaveResults::svFaildEmptyObject:
                {
                    cout << "\nError account was not saved because it's Empty";
                    break;
                    
                }
                    
                    
            }
        }
            
        }
        
    

    

};
