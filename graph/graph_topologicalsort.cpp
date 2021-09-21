#include<bits/stdc++.h>
using namespace std;
void topologicalsort(int n,vector<int> adj[]){
    vector<int>indegree(n,0);
    for (int i = 0; i < n; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
         
    }

   vector<int> ans;
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top=q.front();
        ans.push_back(top);
        q.pop();
        for(auto i:adj[top]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }

}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr[n];
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      arr[u].push_back(v);
    }
    
    topologicalsort(n,arr);
    
}