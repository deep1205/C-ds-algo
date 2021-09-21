#include<bits/stdc++.h>
using namespace std;
void findmissing(int a[],int n);

void findmissing(int a[],int n)
{
  int xo = a[0]; 
    for (int i = 1; i < n-2; i++) 
        xo^= a[i]; 


    for (int i = 1; i <= n; i++) 
        xo ^= i;

  int setbit=xo^(xo & (xo -1));

  int x=0,y=0;

    for (int i = 0; i <n-2; i++)
    {
      if(a[i] & setbit)
     x=x^a[i];
    else
     y=y^a[i];
    }
 


    for (int  i = 1; i <=n; i++)
    {
 if(i & setbit)
     x=x^i;
 else
     y=y^i;
}

cout<<x<<" "<<y;

}


int main() 
{ 
    int arr[] = {1, 3, 5, 6}; 
  
    // Range of numbers is 2 plus size of array 
    int n = 2 + sizeof(arr)/sizeof(arr[0]); 
  
    findmissing(arr, n); 
  
    return 0;
}
