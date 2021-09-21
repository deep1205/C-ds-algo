 #include<bits/stdc++.h>
 using namespace std;



    void binarytodecimal(int n);
 void decimaltobinary(int n)
 {   
     for(int i=7;i>=0;i--)
     { 
         int k=n>>i;
      
         if(k & 1)
       { cout<<"1";
        }
     else
     {
         cout<<"0";
     }
    
      }
 }
     

    void binarytodecimal(int n)
    {      
        int i=0,dec=0;

        while(n!=0)
        {
     int digit=n%10;
     
     dec+=digit<<i;
     i++;
     n=n/10;
             
        }
        cout<<dec;
    }  

 int main()
 {
     int n;
     int s;
     
     cin>>n>>s;

     cout<<" eqyivalent binary form is : ";
     decimaltobinary(n);
     
     cout<<" \n eqyivalent decimal form is : ";
     binarytodecimal(s);
        }