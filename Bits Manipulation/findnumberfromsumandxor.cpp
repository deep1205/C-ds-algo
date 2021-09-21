#include<bits/stdc++.h>
using namespace std;
int main()
{


    int sum,xo;
    cin>>sum>>xo;

    int a=(sum-xo)/2;
    int b=xo+a;

if((a+b==sum) && (a^b==xo))
    cout<<a<<" "<<b;
    else
    {
        cout<<"dont exist";
    }
    
}