#include<bits/stdc++.h>
using namespace std;
 int problem1(vector<int> &prices){
        
        int n=prices.size();
        int mx=0;
        int mn=INT_MAX;
        for(int i=1;i<n;i++){
            mn=min(mn,prices[i-1]);
            mx=max(mx,prices[i]-mn);
        }
        return mx;
        
    
    
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

   cout<< problem1(v);

    


}