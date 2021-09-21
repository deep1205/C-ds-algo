#include<bits/stdc++.h>
using namespace std;
#define auto int
vector<auto> parent(11,0);
vector<auto> sz(11,1);
void make_set(int n,vector<auto>& parent,vector<auto> & sz)
{
    for(auto i=1;i<=n;i++)
    {
        parent[i]=i; //every one is parent o itself
        sz[i]=1;  //rank initailly is 1 
        
    }
}
//find set return absoulte root or parent of n
auto find_set(auto n,vector<auto>& parent,vector<auto>& sz)
{
    if(parent[n]==n)
    return n;
    else
    return parent[n]=find_set(parent[n],parent,sz);  //path compression
}
void union_set(auto a,auto b,vector<auto>& parent,vector<auto>& sz)
{
   a=find_set(a,parent,sz);
   b=find_set(b,parent,sz);
   if(a==b)
   {
       
       return ;

   }
   if(sz[a]<sz[b])
   {
       swap(a,b);
   }
   parent[b]=a;
   sz[a]=sz[a]+sz[b];


}
int main()
{
    int n,t;
    cin>>n;
    cin>>t;
    
    make_set(n,parent,sz);
    while(t--)
    {
        auto a,b;
        cin>>a>>b;
        union_set(a,b,parent,sz);
        cout<<find_set(a,parent,sz)<<" "<<find_set(b,parent,sz)<<endl;
    }
}