#include<bits/stdc++.h>
using namespace std;


 void generatesubstring(string a,int n){
  
  for(int i=0;i<n;i++)
  {
      for(int j=i;j<n;j++)

      {  
           for (int k=i; k<=j; k++) 
          {
                cout<<"["<<a[k]<<"]"<<"";
            
            }
            cout<<",";
            
        
          
      }

  }

    
 }

 void generatesubarray(int a[],int n){
  
  for(int i=0;i<n;i++)
  {
      for(int j=i;j<n;j++)

      {  
           for (int k=i; k<=j; k++) 
            {
                cout<<"["<<a[k]<<"]"<<"";
            
            }
            cout<<",";
            
  
          
        
          
      }

  }

    
 }
int main()
{
  int a[5]={1,2,3,4,5};
  int n=sizeof(a)/sizeof(a[0]);
  generatesubarray(a,n);
 
 cout<<endl;

  string s="abcd";
  generatesubstring(s,4);
  



}