#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBanckClient.h"

#include <iomanip>
class clsDeleteClientScreen : protected clsScreen{
    
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
    
   static  void ShowDeleteClient()
    {
       
       if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
           return ;//this will exit the function and it will not
       }
        
       string Title ="\t Delete Client Screen ";
       _DrawScreenHeader(Title);
        string AccountNumber = "";
        char Delete ='n';
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
               cin >> Delete;
        if (Delete=='Y'||Delete=='y') {
            
            if(Client1.Delete()){
                cout<<"\nClient Deleted Successfully.\n";
                _PrintClient(Client1);
            }
            else{
                cout<<" \n Error :( the Client Was Not Deleted Yet ! .\n";
            }
        }
      
        

        
    }
};
