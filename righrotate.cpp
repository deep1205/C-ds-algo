#include<bits/stdc++.h>
using namespace std;
void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}

void rightrotate(string &s, int d)
{
    leftrotate(s, s.length() - d);
}
int main(){
    string ans;
    cin>>ans;
    int n;
    cin>>n;
    rightrotate(ans,n);
    cout<<ans;

}