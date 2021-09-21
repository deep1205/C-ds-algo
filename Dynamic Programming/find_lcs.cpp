#include<bits/stdc++.h>
using namespace std;
int max(int a,int b);

int lengthoflcs(char*a,char*b,int i,int j)
{
  if(i == 0 || j == 0)
  return 0;
    
    if(a[i-1]==b[j-1])
        return 1+lengthoflcs(a,b,i-1,j-1);
        else
    return max(lengthoflcs(a,b,i-1,j),lengthoflcs(a,b,i,j-1));
}

int max(int m,int n)
{
    return (m>=n) ? m:n;
}
int main()
{
 char a[] = "GFGFGYSYIOIWIN";
         
    char b[] = "GFG";  

int l1=strlen(a);
int l2=strlen(b);

cout<<lengthoflcs(a,b,l1,l2)<<endl;


}