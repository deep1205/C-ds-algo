#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#define int         long long
#define endl         '\n'
#define M             1000000007 

struct myclass{
    vector<int>v;
    myclass(vector<int> x){
       v=x;
    }
};
void solve(){
int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}

int ans=0;
   set<myclass>s;
   for(int i=0;i<n;i++){
       for(int j=i;j<n;j++){
           
           vector<int>temp;
           for(int k=0;k<=j;k++){
               temp.push_back(v[k]);
           }

           if(s.find(temp)!=s.end()){
               ans++;
           }
           else{
               s.insert(myclass(temp));
           }
       }
   }

   cout<<ans;

    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
