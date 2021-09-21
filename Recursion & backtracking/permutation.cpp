
#include<bits/stdc++.h>
using namespace std;

void swap(char*x,char*y)
{
    char temp;
     temp=*x;
    *x=*y;
    *y= temp;
    
}
void printarr(char a[],int n)
{
    for(int i=0;i<n;i++)
    {  
        cout<<a[i];
    }
    cout<<endl;
    }

void printallpermu(char *a ,int l,int r)
{
if(l==r)
{
    printarr(a,r+1);
    return ;
}
for(int i=l;i<=r;i++)
{
    swap((a+l),(a+i));
    printallpermu(a,l+1,r);
    swap((a+l),(a+i));
}

} 
int main()
{
    int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }

    printallpermu(a,0,n-1);
    return 0;
}