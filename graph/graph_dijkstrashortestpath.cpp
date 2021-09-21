#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
//dijkstra is useed to find shortest distance in undirected weighted graph

void dijkstra(int src,int n,vector<pair<int,int>>g[]){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int>distTo(n+1,INT_MAX);
    //priority queue store node with smaller distance at the top  
    distTo[src]=0;
    pq.push({0,src});   //tore ({dist[node],from where} so from src distance is 0)
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

       for(auto it:g[prev]){
           if(distTo[it.first]>distTo[prev]+it.second){   // <---always add that line if else 
           distTo[it.first]=distTo[prev]+it.second;
           pq.push({distTo[it.first],it.first});
           }
       }
    }

   for(int i=1;i<=n;i++){
       cout<<distTo[i]<<" ";
   }
   cout<<endl;


    }
signed main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
   
   
    dijkstra(1, n, adj);


}