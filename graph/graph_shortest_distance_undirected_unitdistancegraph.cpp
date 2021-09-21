#include<bits/stdc++.h>
using namespace std;
void  shortestdistance(int src,int n,vector<int> adj[]){
    vector<int> dist(n,INT_MAX);
    queue<int> q;
    
    q.push(src);
    dist[src]=src;
    while(!q.empty()){
        int top=q.front();  
        q.pop();
        for(auto j:adj[top]){
            int d=dist[top]+1;
            dist[j]=min(dist[j],d);
            q.push(j);
        }
    

    }
    int j=0;
    for(auto i:dist){
        cout<<"Shortest distance from source node to "<<j<< " is "<< i<<endl;
        j++;
    }
}

signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

       int src=0;
      shortestdistance(src,n,adj);

}