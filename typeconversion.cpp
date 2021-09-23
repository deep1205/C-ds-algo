#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
#include <typeinfo>


using namespace std;
#define int         int64_t
#define endl         '\n'
#define M             1000000007 
//ascii value range inclues l to r including l to r
//asccii value of 0 to 9 is [48,57]
//ascii value of A to Z is [65,90]
//ascii value of a to z is [97,122]
//ascii value of space char is 40
//ascii value are characters '0' ,'a','A'

//note int(a)=97 and char(97)=a;

void solve(){
//string to int,
//method 1
string s="1024";       
stringstream  ss(s);
int x;
ss>>x;
cout<<x<<endl;

//method 2 string to int
string d="327813";
int temp=0;
for(int i=0;i<d.size();i++){
    temp=temp*10+(d[i]-'0');
}
cout<<temp<<endl;

//int to string conversion
//method1 use to_string(1234);
///method2 2
int e=455;
ostringstream str1;
str1<<e;
string newstr=str1.str();
cout<<newstr<<endl;





//
//convert char to int by ascii values '0' =0 by
//both are same
int num1='2'-'0'; 
int num2='2'-48;
cout<<num1<<" "<<num2<<endl;

//convert  a to z to 0-25
//both are same
int avalue1='a'-97;
int avalue2='a'-'a';
cout<<avalue1<<" "<<avalue2<<endl;


//char function
//isalpha ,isdigit,isalnum,isupper,islower,toupper,tolower








   
    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
