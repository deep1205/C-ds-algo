
#include<bits/stdc++.h>
using namespace std;
#define   m           1000000007
int64_t multiply(int64_t a, int64_t b)
{
    int64_t res = 0;
    a %= m;
    while (b)
    { if (b & 1)
        {   res = (res + a) % m;
        }
        a = (2 * a) % m;
        b >>= 1;
    }
    return res;
}
void solve(){
int n,q;
cin>>n>>q;
unordered_map<int,int>mp;
vector<int>v(q);
vector<char> ch(q);
for(int i=0;i<q;i++){
    cin>>v[i];
}
for (int i = 0; i < q; i++)
{
    cin >> ch[i];
}
set<pair<char,int>>p;
for(int i = 0; i < q; i++)
{
    p.insert(make_pair(ch[i],v[i]));
}
unordered_map<int,int>d;
for(auto i:p){
    d[i.second]+=1;
}
int ans=1;
for(auto i:d){
int res=26-i.second;
if(res<0){
    res=26;
}
ans=multiply(ans,res);

}
cout<<ans<<endl;
}
signed main(){ 
    int t=1;
   // cin>>t;
    while(t--) solve();
    return 0;
}
