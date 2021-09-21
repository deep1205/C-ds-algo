#include<bits/stdc++.h>
using namespace std;
#define int int64_t
void dfshelper(int node,vector<int>&vis,vector<int> arr[],vector<int>& storeans){
    storeans.push_back(node);
    vis[node]=1;
    for(auto it:arr[node]){
        if(!vis[it]){
            dfshelper(it,vis,arr,storeans);
        }
    }
}
void dfs(int n,vector<int> arr[]){
    vector<int> storeans;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfshelper(i,vis,arr,storeans);
        }
    }
    for(auto i:storeans){
        cout<<i<<" ";
    }

}
void bfs(int n,vector<int> arr[]){
    vector<int>ans;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            queue<int>q;
            q.push(i);
             vis[i]=1;
             while(!q.empty()){
                 int top=q.front();
                 q.pop();
                 ans.push_back(top);
                 for(auto x:arr[top]){
                     if(!vis[x]){
                         q.push(x);
                         vis[x]=1;
                     }
                 }
             }
        }

    }
    
    //bfs traversal
    for(auto i:ans)
    {   
        cout<<i<<" ";
    }
}

//cycle detection using bfs in undirected
bool iscyclepresent(int s,int V,vector<int> arr[],vector<int> &vis){
    queue<pair<int,int>>q;
    vis[s] = 1;
    q.push({s, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : arr[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, node});
            }
            else if (parent != it)
            {
                return true;
            }
        }
        


    }

    return false;
}


bool cycledetection(int V,vector<int>arr[]){
    vector<int>vis(V+1,0);
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            if(iscyclepresent(i,V,arr,vis))
            return true;
        }
    }
    return false;
}
////////////////////////cycle detection using bfs in undirected---///////////// 

//bipartite-if all component have even length cycle it is bipartiete ,if any one component have odd length cycle it is not a  bipartite
// so all component must have even length cycle then it is bipartite else not

bool isbipartite(int node,vector<int>&color,vector<int> arr[] ){
    queue<int>q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto it:arr[top]){
            if(color[it]==-1){
                color[it]=1-color[top];
                q.push(it);

            }
            else if(color[it]==color[top]){
                return false;
            }

        }
    }
    return true;
}
bool checkbipartite(int n,vector<int> arr[]){ 
    vector<int> color(n+1,-1);
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!isbipartite(i,color,arr)){   //if for any coponent it has odd length  cycle  or it is not a bipartite then it is not biparttite                  
                return false;
            }

        }
    }

    //it means all components have even length cycle so it it bipartite
    return true;

}
signed main(){
    //assume 0 base indexing
    int n,m;
    cin>>n>>m;
    vector<int> arr[n+1];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        
        arr[u].push_back(v);
        arr[v].push_back(u);

    }

   
     
    //bfs traversal
    // bfs(n,arr);
    ////


    ///dfs traversal
   /// dfs(n,arr);


   //cycledetection(n,arr);
  // checkbipartite(n,arr);

  //cycle detection in directed graph

    
}
