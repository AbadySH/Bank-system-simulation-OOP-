#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBanckClient.h"
#include <iomanip>

class clsFindClientScreen : protected clsScreen {
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
public:
    
    
    static void ShowFindScreen(){
        
        
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {
            return ;//this will exit the function and it will not
        }
         
        
        _DrawScreenHeader("\t Find Client Screen \n");
        
        
        cout<<"\n If You Want to Find Client By Account Number Press 1 , If You Want to Find Client By AccountNumber and PinCode Press 2 \n ";
        short Chooce =clsInputValidate::ReadShortNumber();
        if (Chooce ==1 ) {
            cout<<"\n Please Entr Account Number :\n";
            string AccountNumber =clsInputValidate::ReadString();
           clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            if (Client1.IsEmpty()) {
                cout<<"\n client Was Not Found ! \n ";
            }
            else {
                cout<<"\n client Ws Found :-) \n ";
                _PrintClient(Client1);
            }
            
        }
        else{
            cout<<"\n Please Entr Account Number :\n";
            string AccountNumber =clsInputValidate::ReadString();
            
            cout<<"\n Please Entr PinCode:\n";
            string Pincode =clsInputValidate::ReadString();
            
            clsBankClient Client1 = clsBankClient::Find(AccountNumber,Pincode);
            if (Client1.IsEmpty()) {
                cout<<"/t/t/t/t\n client Was Not Found ! \n ";
            }
            else {
                cout<<"\n client Was Found :-) \n\n\n";
                _PrintClient(Client1);
            }
            
            
        }
    }

};
