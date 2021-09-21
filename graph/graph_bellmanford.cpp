#include<bits/stdc++.h>
using namespace std;
struct node{
    int u;
    int v;
    int w;
    node(int first,int second,int third){
        u=first;
        v=second;
        w=third;
    }
};
// BEllman ford is useed to find negative cycle and shortedt distance array in case of negatiev weight
// time coompllexity =n*e;
int main(){
    int n,m;
    cin>>n>>m;
    vector<node>edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(node(u,v,w));
    }
    int src=0;
    cin>>src;
    int inf=100000000;
    vector<int>dist(n,inf);
    dist[src]=0;
    //relaxation n-1 times and check if dist[u]+w<dist[v] then store it (assume(u,v,w))
    for(int i=1;i<=n-1;i++){
        for(auto j:edges){
            if(dist[j.u]+j.w<dist[j.v]){
                dist[j.v]=dist[j.u]+j.w;
            }
        }
    }

    int fl=0;
    for(auto i:edges){
        if(dist[i.u]+i.w<dist[i.v]){
            cout<<"Negative cycle present"<<endl;
            fl=1;
            break;
        }
    }
   

   //if fl==0 that means no negative cycle present and we get a shortedt distanec array

    if(!fl){
    for(auto i:dist){
        cout<<i<<" ";
    }
    }


}