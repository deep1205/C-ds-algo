#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;

#define endl         '\n'
#define M             1000000007 

bool check(int v[][],int m,int n) {
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==1){
                return 0;
            }
        }
    }
    return 1;

}
int solve(){

int v[3][3]={{2,1,1},{1,1,0},{0,1,1}};
int m=3;
int n=3;
queue<pair<int,int>,int>q;
int vis[3][3];
memset(vis,0,sizeof(vis));
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(v[i][j]==2){
            q.push({i,j},0);
            vis[i][j]=1;
        }
    }
}
while(q.empty()){
pair<int,int>pos=q.front().first;
int time=q.front().second;

if(check(v,m,n)){
    return time;
}

int x=pos.first;
int y=pos.second;

if(v[x-1][y]==1 && vis[x-1][y]==0){
    q.push({x-1,y},time+1);
    vis[x-1][y]=1;
}
if (v[x + 1][y] == 1 && vis[x - 1][y] == 0)
{
    q.push({x + 1, y}, time + 1);
    vis[x + 1][y] = 1;
}
if (v[x ][y+1] == 1 && vis[x - 1][y] == 0)
{
    q.push({x , y+1}, time + 1);
    vis[x ][y+1] = 1;
}
if (v[x ][y-1] == 1 && vis[x - 1][y] == 0)
{
    q.push({x, y-1}, time + 1);
    vis[x ][y-1] = 1;
}

}
return -1;
   
    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--) cout<<solve();
    return 0;
}
