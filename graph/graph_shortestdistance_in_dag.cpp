#include<bits/stdc++.h>
using namespace std;
vector<int> toposort(vector<pair<int,int>>adj[],int n){
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j.first]++;
        }
    }

    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int top = q.front();
        ans.push_back(top);
        q.pop();
        for (auto i : adj[top])
        {
            indegree[i.first]--;
            if (indegree[i.first] == 0)
            {
                q.push(i.first);
            }
        }
    }
     reverse(ans.begin(),ans.end());
     return ans;

}

void shortestdistance(int src,int n,vector<pair<int,int>>adj[]){
    vector<int>topo=toposort(adj,n);
    vector<int>dist(n,INT_MAX);
    
    stack<int>s;
    for(auto i:topo){
        s.push(i);
    }
    
    dist[src]=src;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(dist[top]!=INT_MAX){
            for(auto j:adj[top]){
                dist[j.first]=min(dist[j.first],dist[top]+j.second);
            }
        }
    }

    for(auto i:dist){
        cout<<i<<" ";
    }
     
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> arr[n];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        arr[u].push_back({v,w});
        
    }
    
   shortestdistance(0,n,arr);
    



}