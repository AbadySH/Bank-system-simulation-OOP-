#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBanckClient.h"
#include <iomanip>


class clsTotalBalancesScreen : protected clsScreen {
    
    private :
    static void _PrintClientBalanceRecordLine(clsBankClient Client)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.GetFirstName();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();
    }
    public :
    static   void ShowAClientsBalancesScreen()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        double TotalBalances = 0;
        
        
        cout << "\n\t\t\t\t\tClient Blansces List (" << vClients.size() << ") Client(s).\n";
        cout << "____________________________________________________________________________________________________\n";
        
        cout << "| " << setw(15) << left << "Accout Number";
        cout << "| " << setw(40) << left << "Client Name";
        cout << "| " << setw(12) << left << "Balance";
        cout << "\n____________________________________________________________________________________________________\n";
        if (vClients.size()==0) {
            
            cout<<"t/t/t/No Clients Availabale In the system !";
            
        } else
            
            TotalBalances=clsBankClient::GetTotalBalances();
        
        for (clsBankClient Client : vClients)
        {
            
            _PrintClientBalanceRecordLine(Client);
            cout << endl;
        }
        
        
        
        cout << "____________________________________________________________________________________________________\n";
        
        cout<<"\t\t\t\t\t\t\t\t\t\tTotal Clinents Balances : "<<TotalBalances<<" $"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t( "<<clsUtil::NumberToText(TotalBalances)<<" $)\n";
        
        
    }
};
