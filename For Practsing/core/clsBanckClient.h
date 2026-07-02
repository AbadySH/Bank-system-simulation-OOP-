#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"

#include "clsString.h"
#include "clsUser.h"
#include "clsUtil.h"
#include <vector>
#include <fstream>
#include "Global.h"
using namespace std;

static const string ClientsFileName ="/Users/badyalshryf/Desktop/Bank system simulation (OOP)/ClientFile.txt";
static const string TransferLog_FileName ="/Users/badyalshryf/Desktop/Bank system simulation (OOP)/Users.txt";
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMode =2};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete =false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData = clsString::vSplitString(Line, Seperator);
        if (vClientData.size() < 7) {
            // Not enough fields
            return _GetEmptyClientObject();   }
            // File order: AccountNumber, PinCode, FirstName, LastName, Email, Phone, Balance
            return clsBankClient(enMode::UpdateMode,
                                 vClientData[2],   // FirstName
                                 vClientData[3],   // LastName
                                 vClientData[4],   // Email
                                 vClientData[5],   // Phone
                                 vClientData[0],   // AccountNumber
                                 clsUtil::DecryptText( vClientData[1]),   // PinCode
                                 stod(vClientData[6])); // Balance
      }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord +=   clsUtil::EncryptText( Client.GetPinCode()) + Seperator;
            stClientRecord += Client.GetFirstName() + Seperator;
            stClientRecord += Client.GetLastName() + Seperator;
            stClientRecord += Client.GetEmail() + Seperator;
            stClientRecord += Client.GetPhone() + Seperator;
             
            stClientRecord += to_string(Client.GetAccountBalance());
            return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open(ClientsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open(ClientsFileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C._MarkForDelete == false)
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }
    
    void _AddNew(){
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open(ClientsFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
   
    string _PreparTransferLogRecord(float Amount ,clsBankClient& DestinationClient ,string UserName)
   {
       
        string Seperator = "#//#";
       string TransferRecord = "";
       
        TransferRecord +=clsDate::GetSystemDateTimeString()+ Seperator;
        TransferRecord += AccountNumber() + Seperator;
        TransferRecord += DestinationClient.AccountNumber()+ Seperator;
        TransferRecord += to_string(Amount)+Seperator;
        TransferRecord += to_string(GetAccountBalance())+Seperator;
        TransferRecord += to_string(DestinationClient.GetAccountBalance())+Seperator;
        TransferRecord+=UserName;
        
      

       return TransferRecord;

   }
      void _RegiterTransferLog( float Amount ,clsBankClient& DestinationClient ,string UserName)
   {
        string DataLine = _PreparTransferLogRecord(Amount, DestinationClient, UserName);
       fstream MyFile;
       MyFile.open(TransferLog_FileName, ios::out | ios::app);//overwrite

      

       if (MyFile.is_open())
       {

                   //we only write records that are not marked for delete.
                   
                   MyFile << DataLine << endl;
                   MyFile.close();

       }

   }
public:
    struct stTransferRecoed {
        string DateTime;
        string SourceClient;
        string DestinationClient;
        float Amount;
        float SourceClientAmount;
        float DestinationClientAmount;
        string UserName;
        
    };
    static stTransferRecoed ConvertTransferRecoed(string Line, string Seperator = "#//#")
     {
        stTransferRecoed TransferRecoed;
         vector<string> vTransferRecoed;
        vTransferRecoed = clsString::vSplitString(Line, Seperator);

        TransferRecoed.DateTime= vTransferRecoed[0];
        
        TransferRecoed.SourceClient = vTransferRecoed[1];
        TransferRecoed.DestinationClient = vTransferRecoed[2];
        TransferRecoed.Amount= stod(vTransferRecoed[3]);
        TransferRecoed.SourceClientAmount= stod(vTransferRecoed[4]);
        TransferRecoed.DestinationClientAmount= stod(vTransferRecoed[5]);
        TransferRecoed.UserName = vTransferRecoed[6];
        return TransferRecoed;
     }
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }
  
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
   
    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }


   static clsBankClient Find(string AccountNumber)
    {
       

        fstream MyFile;
        MyFile.open(ClientsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
              
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {

     

        fstream MyFile;
        MyFile.open(ClientsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
              
            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 ,svFaildAccountNumberExists =2};

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
        
                return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

            case enMode::AddNewMode:
            {
                if (clsBankClient::IsClientExist(_AccountNumber)) {
                   
                    return enSaveResults::svFaildAccountNumberExists;
                }
                else
                {
                    _AddNew();
                    
                    _Mode=enMode::UpdateMode;
                    return enSaveResults::svSucceeded;
                    
                    break;
                }
            }

        }



    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }
    
    
    bool Delete()
    {
//       string AccountNumber,
       vector<clsBankClient> _vClients;
       _vClients=_LoadClientsDataFromFile();
        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() ==_AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }
        }
        _SaveCleintsDataToFile(_vClients);
        
        *this =_GetEmptyClientObject();
        
        return true;
    }
    static vector<clsBankClient> GetClientsList()
    {
        
        return _LoadClientsDataFromFile();
        
    }
    
    static double GetTotalBalances(){
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        double TotalBalances = 0;
        
        for (clsBankClient Client : vClients)
        {
            
            TotalBalances+=Client.GetAccountBalance();
           
        }
        return TotalBalances;
    }
    void Deposit(double Amount){
        _AccountBalance += Amount;
        Save();
    }
    
    void Withdraw(double Amount){
       
            _AccountBalance -= Amount;
            Save();
        }
    bool Transfer(float Amount ,clsBankClient& DestinatoinClient,string UserName){
        
        if (Amount>_AccountBalance) {
            return false;
        }
        Withdraw(Amount);
        DestinatoinClient.Deposit(Amount);
        _RegiterTransferLog(Amount, DestinatoinClient,UserName );
        return true;
    }
    
  
    
    static vector<stTransferRecoed> GetTransferLog(){
        vector<stTransferRecoed> vTransferRecoed ;
        fstream MyFile;
        MyFile.open(TransferLog_FileName, ios::in );//ReadOnly


        if (MyFile.is_open())
        {
            
            string Line;
            stTransferRecoed TransferRecoed ;
            
            while (getline(MyFile, Line))
            {
                TransferRecoed = ConvertTransferRecoed(Line);
                vTransferRecoed.push_back(TransferRecoed);
            }
                MyFile.close();
            
        }
        return vTransferRecoed;
    }
};

