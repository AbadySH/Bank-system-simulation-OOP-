#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBanckClient.h"
#include <iomanip>

class clsClientListScreen : protected clsScreen {
    private :
   static void _PrintClientRecordLine(clsBankClient Client) {
       
          

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetPhone();
        cout << "| " << setw(20) << left << Client.GetEmail();
        cout << "| " << setw(10) << left << Client.GetPinCode();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();

       

    }
public:
    
  static void ShowTheClientsList() {
        
      if (!CheckAccessRights(clsUser::enPermissions::pListClients)) {
          return ;//this will exit the function and it will not
      }
       
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
      string Title ="\t Client Screen ";
      string SubTitle= "\n\t\t\t\t\tClient List (" + to_string(vClients.size()) +") Client(s)." ;
      
      _DrawScreenHeader(Title,SubTitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};
