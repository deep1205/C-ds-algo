#include<bits/stdc++.h>
using namespace std;

void printpath(int i,int j,int n,int m ,string s){

    if (i >= n - 1 || j >= m - 1)
    {
        return;
    }
    if(i==n-1 && j==m-1){
        cout<<s<<endl;
        return ;
           
    }
   

        s+='R';
        printpath(i,j+1,n,m,s);
        s.pop_back();
    

        s+='D';
        printpath(i+1,j,n,m,s);
        s.pop_back();
      
        
        
    
}
int main(){
     int n,m;
    
     cin>>n>>m;
    int i=0,j=0;
 string s="";
    //count path from i j to end n,m;
    printpath(i,j,3,2,s);
}