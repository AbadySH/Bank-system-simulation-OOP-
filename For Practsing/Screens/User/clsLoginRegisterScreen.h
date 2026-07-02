#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsDate.h"
#include <iomanip>
#include <string>

class clsLoginRegisterScreen : protected clsScreen {
    private :
    static void _PrintLoginRegisterRecordLine(clsUser::stRegisterLoginRecoed LoginRecord) {
        
        
        
        cout << setw(8) << left  << "| " << setw(35) << left << LoginRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRecord.UserName;
        cout << "| " << setw(20) << left << LoginRecord.PassWord;
        cout << "| " << setw(10) << left << LoginRecord.Permission;
        
        
        
        
    }
public:
    
    static void ShowLoginRegister() {
        if (!CheckAccessRights(clsUser::enPermissions::pLogRegister)) {
            return ;//this will exit the function and it will not
        }
        vector<clsUser::stRegisterLoginRecoed> vLoginRegisterRecoed = clsUser::GetLoginRegisterList();
        string Title ="\t Login Register Screen ";
        string SubTitle= "\n\t\t\t\t\tClient List ("+ to_string(vLoginRegisterRecoed.size())+ ") Client(s)." ;
        
        
        _DrawScreenHeader(Title,SubTitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        
        cout << "| " << left << setw(35) << "Date ";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(20) << "PAsword";
        cout << "| " << left << setw(10) << "Permission";
        
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        
                if (vLoginRegisterRecoed.size() == 0)
                    cout << "\t\t\t\tNo Login Register  Available In the System!";
                else
       
        for (clsUser::stRegisterLoginRecoed Record  : vLoginRegisterRecoed) {
            _PrintLoginRegisterRecordLine(Record);
            cout << endl;
   
        }
            
            
     

       
    
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    
    
}
    
};
