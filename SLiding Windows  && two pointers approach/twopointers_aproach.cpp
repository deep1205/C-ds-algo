#include<bits/stdc++.h>
using namespace std;


bool isfound(int a[],int n,int x)
{

   int l,r,flag=0;
   for(int i=0;i<=n-3;i++)
   {
   l=i+1;
   r=n-1;
     while(l<r)
     {
         if(a[l]+a[r]+a[i] == x)
         { 
            cout<<"triplet is "<<a[i]<<" "<<a[l]<<" "<<a[r];
             return true;
         }
         else if(a[l]+a[r]+a[i]<x)
         l++;
         
         else
         r--;

     }
   }
   
   if(flag==0)
   cout<<"not found";
   return false;  
   
}
   
int main()
{

    int n,x,z;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    
    }

    sort(a,a+n);
    isfound(a,n,x);

}