 #pragma once
 #include<iostream>
 #include<vector>
#include<string>

 using namespace std;

 class clsString {
    
     string _value ;
     public :
     
     clsString(){
         _value ="";
     }
     clsString(string value){
         _value = value;
     }
    
     void setValue(string value){
         _value =value;
     }
     string getValue(){
         return _value;
     }
     
     static short lenght(string S1){
         
         return S1.length();
     }
      short lenght(){
          cout << "\nThe lenght of the String is : \n" ;
         return _value.length();
     }
     static string PrintFirstLetterOfEachWord( string S1 )
     { bool isFirstLetter = true ;
     cout << "\nFirst letters of this string: \n" ;
     for
     (
     short
     i = 0; i <
     S1
     .length(); i++)
     {
     if
     (
     S1
     [i] !=
     ' '
     && isFirstLetter)
     {
     cout <<
     S1
     [i] << endl;
     }
     isFirstLetter = (
     S1
     [i] ==
     ' '
     ?
     true
     :
     false
     );
     }
         return "";
     }
     string PrintFirstLetterOfEachWord(){
         return PrintFirstLetterOfEachWord(_value);
     }
     static string UpperFirstLatterOfEachWord( string S1 ) {
         bool IsFirstLatter =true;
         cout<<"\n Upper First Latter Of The String : \n";
         for (short i=0; i<S1.length(); i++) {
             
             
             if (S1[i]!=' ' && IsFirstLatter ){
                
                 S1[i]=toupper(S1[i]);
             }
             IsFirstLatter= (S1[i] == ' ')? true :false;
           
            
         }
         return S1;
         
     }
     string UpperFirstLatterOfEachWord(){
        
         return UpperFirstLatterOfEachWord(_value);
     }
     static string UpperAllLatterOfTheString( string S1 ) {
        
         
         for (short i=0; i<S1.length(); i++) {
             
             
             if (S1[i]!=' ' ){
                
                 S1[i]=toupper(S1[i]);
             }
         
           
            
         }
         return S1;
         
     }
     string UpperAllLatterOfTheString(){
         return UpperAllLatterOfTheString(_value);
     }
     static  string LowerAllLatterOfTheString( string S1 ) {
        
         
         for (short i=0; i<S1.length(); i++) {
             
             
             if (S1[i]!=' ' ){
                
                 S1[i]=tolower(S1[i]);
             }
         
           
            
         }
         return S1;
         
     }
     string LowerAllLatterOfTheString(){
         cout<<"\n Lower All Latter Of The String : \n";
         return LowerAllLatterOfTheString(_value);
     }
     static  char InvertLatterCase( char Ch1 ) {
         
        
        
         return isupper(Ch1)? tolower(Ch1):toupper(Ch1);
         
     }
     char InvertLatterCase(){
         cout<<"\n Invert Latter Case : \n";
         return InvertLatterCase(ReadChar());
     }

     static   string InvertAllStringLatterCase( string S1 ) {
         
        
         for (short i=0; i<S1.length(); i++) {
               
               
              
                  
             S1[i]=InvertLatterCase(S1[i]);
               }
             return S1;
     }
     string InvertAllStringLatterCase(){
         cout<<"\n Invert All String Latter Case : \n";
         return InvertAllStringLatterCase(_value);
     }
     static   short CountACaptelLatterOfTheString( string S1 ) {
         cout<<" The Count of A Captel Latter Of TheString is : ";
         short count =0;
         for (short i=0; i<S1.length(); i++) {
             
             
             if (isupper(S1[i])){
                
                 count++;
             }
         
           
            
         }
         
         return count;
     }
     short CountACaptelLatterOfTheString(){
         return CountACaptelLatterOfTheString(_value);
     }
     static short CountASmallLatterOfTheString( string S1 ) {
         cout<<" The Count of A Small Latter Of The String is : ";
         short count =0;
         for (short i=0; i<S1.length(); i++) {
             
             
             if (islower(S1[i])){
                
                 count++;
             }
         
           
            
         }
         
         return count;
     }
     short CountASmallLatterOfTheString(){
         return CountASmallLatterOfTheString(_value);
     }
      enum enWhattocount {capitalLettres =0 ,SmallLettres=1 ,All=3};
     
     static short CountAAllLatterOfTheString( string S1 ,enWhattocount WhatTocount=enWhattocount::All ) {
         if (WhatTocount==enWhattocount::All) {
             cout<<S1.length();
         }
         
         short count =0;
         for (short i=0; i<S1.length(); i++) {
             
             
             if (WhatTocount==enWhattocount::capitalLettres && isupper(S1[i])){
                
                 count++;
             }
         
             if (WhatTocount==enWhattocount::SmallLettres&& islower(S1[i])){
                
                 count++;
             }
            
         }
         
         return count;
     }
     short CountAAllLatterOfTheString(){
         
         
         cout<<"\nthe string length is : "<<_value.length();
         cout <<"\n Captell latters are : "<<CountAAllLatterOfTheString(_value,enWhattocount::capitalLettres);
         cout <<"\n Small latters are : "<<CountAAllLatterOfTheString(_value,enWhattocount::SmallLettres)/10;
         return 0;
         }
     static char ReadChar(){
         char Ch1 ;
         cout<<" Please entr the Character : \n";
         cin>>Ch1;
         return Ch1;
     }

     static   short CountSpecificCharInString( string S1 ,char Letter,bool MatchCase =true) {
        
         short count =0;
         cout<<" \n the Character ["<<Letter<<"] Repeated  :";
         for (short i=0; i<S1.length(); i++) {
             
             
             if (MatchCase){
                 if ( S1[i] ==Letter )
                 count++;
                 
             }
             else {
                 if (tolower( S1[i]) ==tolower(Letter )) {
                     count++;
                 }
             }
           
            
         }
        
         return count;
     }
     short CountSpecificCharInString(){
         cout<<"\n The Count of A Small Latter Of The String after choosing the Letter is   : \n";
         return CountSpecificCharInString(_value,ReadChar());
     }
     
     static bool IsvowelBool( char Ch1) {
         Ch1=tolower(Ch1);
           return ((Ch1=='a')||(Ch1=='e')||(Ch1=='i') ||(Ch1=='o')||(Ch1=='u'));
     }
     static  short CountVowelstring( string S1 ) {
        
         short count =0;
         for (short i=0; i<S1.length(); i++) {
             
             
            
             if ( IsvowelBool(S1[i]))
                 count++;
                 
             }
         
         cout << "\n Vowels in string Are :  ";
         for (int i = 0; i < S1.length(); i++)
     {
        
         if ( IsvowelBool(S1[i]))
             cout << S1[i] << "  ";
             }
             
         

   
           
         cout<<"\n Number of Vowels in text is :  ";
         
         return count;
     }
     short CountVowelstring( ){
         
         return CountVowelstring(_value);
     }
     
    
     static   string  Isvowel(){
        
         
         cout<<"  Entr the  Letter if you want to Know if it's vowel  or Not ! : \n";
         char Ch1 =ReadChar();
            
             
             if (IsvowelBool(Ch1))
             {
                 cout<<" \n YEs Letter \'"<<Ch1<<"\' is vowel   "<<endl;;
             }
             else{
                 cout<<"\n No Letter \'"<<Ch1<<"\' is not vowel   "<<endl;
             }
             
             
             
         
         return " ";
         
     }
         
    
     
     static  string PrintString(string S1 )
     {
         cout<<"\nyour string words are :\n";
         string delim=" ";
         string sWord;
         short pos=0;
         
         
         while ((pos=S1.find(delim)) !=  std::string::npos) {
             sWord=S1.substr(0,pos);
             if  (sWord!=""){
                    
                 cout<< sWord<<endl;
                 }
             
             S1.erase(0, pos + delim.length());
         }
         if (S1!="") {
             cout<<S1<<"\n";
         }
        
         return " ";
         }
     
     string PrintString(){
         return PrintString(_value);
     }
     
     
     static  vector<string> vSplitString(string S1,string Delim )
     {
         vector<string> vString ;
         
         
         string sWord;
         short pos=0;
         
         
         while ((pos=S1.find(Delim)) !=  std::string::npos) {
             sWord=S1.substr(0,pos);
             if  (sWord!=""){
                 vString.push_back(sWord);
                 
                 
                 }
             
             S1.erase(0, pos + Delim.length());
         }
         if (S1!="") {
            
             vString.push_back(S1);
             
         }
        

             
         
         return vString;
         }
     string SplitString(){
         vector<string> vString ;
        
         vString=vSplitString(_value, " ");
         cout<<" Tokens = "<<vString.size()<<endl;
         for (string &s :  vString) {
             cout<<s<<endl;
         }
         
         cout<<"\n";
         return " ";
        
     }
     
     static string TirmLeft(string S1){
         for (short i=0; i<S1.length(); i++) {
             if (S1[i]!=' ') {
                 return S1.substr(i,S1.length()-i);
             }
         }
         
         return "";
     }
       string TirmLeft(){
         cout<<"\n Tirm Left\t  = ";
         return TirmLeft(_value);
     }
     static string TirmRight(string S1){
         for (short i=S1.length()-1; i>=0; i--) {
             if (S1[i]==' ') {
                 return S1.substr(0,i+1);
             }
         }
         
         return "";
     }
     string TirmRight(){
         cout<<"\n Tirm Right\t = ";
         return TirmRight(_value);
     }
     static  string Tirm(string S1){
         
         
         return TirmLeft(TirmRight(S1));
     }
     string Tirm(){
         cout<<"\n Tirm      \t = ";
         return Tirm(_value);
     }
     static string vJoinString(vector<string> vString,string Delim )
     {
         string S1 ="";
         for (string &S : vString) {
             S1= S1+S+Delim;
         }
        
         
            

             
             
         
         return S1.substr(0,S1.length()-Delim.length());
         }
     static  string ReadString(){
         string S1 ;
        
         getline(cin >> ws, S1);
         return S1;
     }
     string JoinString(){
         vector<string> vString ={ReadString()} ;
         cout<<"\nVectoer After join :\n";
         cout<< _value <<" "<<vJoinString(vString, " ");
         return " ";
     }
     
     static  string ReverseWordsInString(string S1)
     {
         vector<string> vString;
         string S2 = "";
         cout << "\nString after reversing words:\n\n";
         vString = vSplitString(S1, " ");

         vector<string>::iterator iter = vString.end();
         while (iter != vString.begin())
         {
             --iter;
             S2 += *iter + " ";
         }

         S2 = S2.substr(0, S2.length() - 1);
         
         return S2;
     }
     string ReverseWordsInString(){
         return ReverseWordsInString(_value);
     }
     
     static  string RemovePaunctuationsFromString (string S1){
         string S2 =" ";
         for (short i =0; i<S1.length(); i++) {
             if (!ispunct(S1[i])) {
                 S2+=S1[i];
             }
         }
         return S2;
     }
    
     string RemovePaunctuationsFromString(){
         cout << "\nString after Remove Paunctuations :\n\n";
         return RemovePaunctuationsFromString(_value);
     }
     
     
     
     //############################
     
     static  string ReplacewordInStringUsingSpilt(string S1,string StringToReplace,string sReplaceTo,bool MatchCase =true)
     {
         vector<string> vstring =vSplitString(S1," ");
         for (string& s :vstring)
         {
             if (MatchCase)
             {
                 if (s==StringToReplace)
                 {
                     s=sReplaceTo;
                 }
                 
                 
             }
             else
             {
             if (LowerAllLatterOfTheString(s)==LowerAllLatterOfTheString(StringToReplace))
                 {
                     s=sReplaceTo;
                 }
             }
         }
         
         return vJoinString(vstring," ");
     }
     
     string ReplacewordInStringUsingSpilt(){
         
         cout<<" Entr the  String To Replace : \n";
         string StringToReplace =ReadString();
         cout<<" Entr string you want to replace to : \n ";
         string ReplaceTo = ReadString();
         
         
             cout << "\n\nReplace with match case : \n";
             cout<<ReplacewordInStringUsingSpilt(_value, StringToReplace, ReplaceTo);
           
         
             cout << "\n\nReplace with don't match case: \n";
             cout<<ReplacewordInStringUsingSpilt(_value, StringToReplace, ReplaceTo,false);
             cout<<endl;
         
         return " ";
     }
     
     static int Readperfectnumber( )
     {
        //  string message = " Please Entr A Perfect Number : \n";
         int number =0;
         do
         {
             
             cin >> number;
         } while (number <= 0);
         return number;
     }

     static float Readfloatnumber( )
     {
        //  string message = " Please Entr A Perfect Number : \n";
         float number =0;
         do
         {
             
             cin >> number;
         } while (number <= 0);
         return number;
     }
    static string  ConvertNumbeToText(int number )
     {
        
        
         if (number == 0)
             return "";

         if (number >= 1 && number <= 19)
         {
             string arr[] = {
                 "", "one", "two", "three", "four", "five", "six", "seven",
                 "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                 "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
             };
             return arr[number] + " ";
         }

         if (number >= 20 && number <= 99)
         {
             string arr[] = {
                 "", "", "twenty", "thirty", "forty",
                 "fifty", "sixty", "seventy", "eighty", "ninety"
             };
             return arr[number / 10] + " " +  ConvertNumbeToText(number % 10);
         }

         if (number >= 100 && number <= 199)
             return "one hundred " +  ConvertNumbeToText(number % 100);

         if (number >= 200 && number <= 999)
             return  ConvertNumbeToText(number / 100) + "hundred " +  ConvertNumbeToText(number % 100);

         if (number >= 1000 && number <= 1999)
             return "one thousand " +  ConvertNumbeToText(number % 1000);

         if (number >= 2000 && number <= 99999)
             return  ConvertNumbeToText(number / 1000) + "thousand " +  ConvertNumbeToText(number % 1000);

         if (number >= 1000000 && number <= 1999999)
             return "one million " +  ConvertNumbeToText(number % 1000000);

         if (number >= 2000000 && number <= 99999999)
             return  ConvertNumbeToText(number / 1000000) + "million " +  ConvertNumbeToText(number % 1000000);

         if (number >= 1000000000 && number <= 1999999999)
             return "one billion " +  ConvertNumbeToText(number % 1000000000);

         if (number >= 2000000000)
             return  ConvertNumbeToText(number / 1000000000) + "billion " +  ConvertNumbeToText(number % 1000000000);

         return "";
     }
     
     string  ConvertNumbeToText(){
         return  ConvertNumbeToText(Readperfectnumber());
     }
     static void PrintTableHeader()
     {
     cout << "\n\n\t\t\t Multipliaction Table From 1 to 10\n\n";
     cout << "\t";
     for (int i = 1; i <= 10; i++)
     {
     cout << i << "\t";
     }
     cout << "\n___________________________________________________________________________________\n";
     }
    static string ColumSperator(int i)
     {
     if (i < 10)
     return "  |";
     else
     return " |";
     }
     static void PrintMultiplicationTable()
     {
     PrintTableHeader();
     for (int i = 1; i <= 10; i++)
     {
     cout << " " << i << ColumSperator(i) << "\t";
     for (int j = 1; j <= 10; j++)
     {
     cout << i * j << "\t";
     }
     cout << endl;
     }
     }
     static void printInvertedLatter(int number)
     {
         
         
        
         
         for(int i =65+number-1;i>=65;i--)
          {
              
            
             for (int j=1;j<=number-(65+number-1-i);j++){
                 
                      
                      cout<<char(i);
         
                 
              }
             
           cout <<"\n";
             
              
             
          }
        
     }
     
     static void PrintWordsFromAAAtoZZZ()
     {
     cout << "\n";
     string word = "";
     for (int i = 65; i <= 90; i++)
     {
     for (int j = 65; j <= 90; j++)
     {
     for (int k = 65; k <= 90; k++)
     {
     word = word + char(i);
     word = word + char(j);
     word = word + char(k);
     cout << word << endl;
     word = "";
     }
     }
     cout << "\n____________________________\n";
     }
     }
    static  string ReadPassword()
     {
     string Password;
     cout << "Please enter a 3-Letter Password (all capital)?\n";
     cin >> Password;
     return Password;
     }
     
     };
     
   

