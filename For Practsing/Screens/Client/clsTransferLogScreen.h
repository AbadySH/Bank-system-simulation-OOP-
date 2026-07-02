#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBanckClient.h"
#include "clsDate.h"
#include <iomanip>


class clsTransferLogScreen : protected clsScreen {
    private :
    static void _PrintTransferRecordLine(clsBankClient::stTransferRecoed TransferRecord) {
        
        
        
        cout << left  << "| " << setw(23) << left << TransferRecord.DateTime;
        cout << "| " << setw(8) << left << TransferRecord.SourceClient;
        cout << "| " << setw(8) << left << TransferRecord.DestinationClient;
        cout << "| " << setw(8) << left << TransferRecord.Amount;
        cout << "| " << setw(10) << left << TransferRecord.SourceClientAmount;
        cout << "| " << setw(10) << left << TransferRecord.DestinationClient;
        cout << "| " << setw(8) << left << TransferRecord.UserName;
       
        
        
        
        
    }
public:
    
    static void ShowTransferLogScreen() {

        
        vector<clsBankClient::stTransferRecoed> vTransferRecoed =
        clsBankClient::GetTransferLog();
        string Title ="\t Transfer Log Screen ";
        string SubTitle= "\n\t\t\t\t  ("+ to_string(vTransferRecoed.size())+ ") Reocrd(s)." ;
        
        
        _DrawScreenHeader(Title,SubTitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        
        cout  << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount  ";
        cout << "| " << left << setw(10) << "s.Balance ";
        cout << "| " << left << setw(10) << "d.Balance ";
        cout << "| " << left << setw(8) << "UserName  ";
        
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
//        
                if (vTransferRecoed.size() == 0)
                    cout << "\t\t\t\tNo Transfer Log  Available In the System!";
                else
       
        for (clsBankClient::stTransferRecoed Record : vTransferRecoed) {
            _PrintTransferRecordLine(Record);
            cout << endl;
   
        }
            
            
     

       
    
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    
    
}
};
