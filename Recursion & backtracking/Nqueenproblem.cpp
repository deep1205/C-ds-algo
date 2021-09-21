#include<bits/stdc++.h>
using namespace std;

bool isSafe(int r,int c,vector<vector<int>>&mat,int n){
 for(int j=c,i=r;j>=0;j--,i){
        if(mat[i][j]==1)
        return false;
    }

for(int i=r,j=c;i>=0 && j>=0;i--,j--){
        if(mat[i][j]==1){
            return false;
        }
    }

 for(int i=r, j=c;i<n && j>=0;j--,i++)
     if(mat[i][j]==1){
       return false;
    }

return true;

}
void Nqueen(int col,vector<vector<int>>mat,int n){
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
       
        cout<<endl;
        cout<<"Next solution"<<endl;
    
        return  ;

    }

    for(int row=0;row<n;row++){
    
        if(isSafe(row,col,mat,n)){
            mat[row][col] = 1;
            Nqueen(col + 1, mat, n);
            mat[row][col] = 0;
        }
       
       
    }
    

}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n,0));
    int col=0;
     Nqueen(col,mat,n);
     
}