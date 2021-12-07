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
int problem2(vector<int>&prices,int fee){
   
        int n = prices.size();
        int dp[n + 1][2];
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    //j==0 means stock nhi h to do option kharido ya na kharido
                    int op1 = -(prices[i] + fee) + dp[i + 1][1];
                    int op2 = dp[i + 1][0];
                    dp[i][j] = max(op1, op2);
                }
                else
                {
                    //j==1 so stock hai ab becho ya na becho
                    int op1 = prices[i] + dp[i + 1][0];
                    int op2 = dp[i + 1][1];
                    dp[i][j] = max(op1, op2);
                }
            }
        }

        return dp[0][0];
    
}
int problem3(vector<int> &prices){
    
        int n = prices.size();
        int dp[n + 1][2][2];
        dp[n][0][0] = 0;
        dp[n][1][1] = 0;
        dp[n][0][1] = 0;
        dp[n][1][0] = 0;
        //cool down comes only when u sell
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {

                    if (j == 0)
                    {
                        //j==0 means stock nhi h to do option kharido ya na kharido
                        //k==0 means no cooldown toh kharido ya na kharido cooldown is 0

                        int op1 = (k) ? 0 : -(prices[i]) + dp[i + 1][1][0];
                        int op2 = dp[i + 1][0][0];
                        dp[i][j][k] = max(op1, op2);
                    }
                    else
                    {
                        //j==1 so stock hai ab becho ya na becho
                        //sell kroge toh cooldown 1 hoga else 0
                        int op1 = prices[i] + dp[i + 1][0][1];
                        int op2 = dp[i + 1][1][0];
                        dp[i][j][k] = max(op1, op2);
                    }
                }
            }
        }

        return dp[0][0][0];
    
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

//1-one transaction allowed atmax
   cout<< problem1(v);


//2-multipple transaction allowed and fee for each transition
int fee;
cin>>fee;
   cout<<problem2(v,fee);




///3-multiple transaction with cooldown comes and not fee
cout<<problem3(v);


   

    


}