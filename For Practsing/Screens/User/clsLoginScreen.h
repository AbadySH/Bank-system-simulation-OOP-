
#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include"clsMainScreen.h"

class clsLoginScreen : protected clsScreen{
    
private:
    
    
    static bool _Login(){
        
        bool LoginFaild = false;
        short FaildLoginCounter =0;
        string UserName ,Password ;
        do {
            if (LoginFaild) {
                FaildLoginCounter++;
                cout<<" \nInvalid UserName/PassWord !\n";
                cout<<" You Have "<<(3-FaildLoginCounter)<<" Trial(s)  To login \n ";
        
                if (FaildLoginCounter==3) {
                    cout<<"\n your are locked After 3 Trial(s)   \n ";
                    return false;
                }
                
            }
            
            cout<<" Entr UserName? ";
            cin>>UserName;
            
            cout<<" Entr PassWord? ";
            cin>>Password;
            
            CurrentUser =clsUser::Find(UserName, Password);
            LoginFaild=CurrentUser.IsEmpty();
            
        } while (LoginFaild);
        
        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
    }
public:
    static bool ShowLoginScreen()
    {
        
        
        _DrawScreenHeader("\t\tLogin Screen");
       return  _Login();
    }
};
