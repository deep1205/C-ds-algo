
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string s;
  cin>>s;
  bool ans=1;
  string temp;
  stringstream ss(s);
  while(ss>>s){
      string temp=s;
      int c=0;
        if(isdigit(temp[0])){
            c++;
        }
        if(c==1){
            for(int i=2;i<temp.size();i+=2){
                if(isdigit(temp[i])){
                    c++;
                }
            }
        }
        else{
            for(int i=1;i<temp.size();i+=2){
                if(isdigit(temp[i]));
                c++;
            }
        }

        cout<<c;
        if(c<3){
            ans=0;
            cout<<"False";
            return 0;
        }   
  }
  if(ans){
      cout<<"True";
  }
}