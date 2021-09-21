#include<bits/stdc++.h>
using namespace std;
int prefixExpression(string s){
    stack<int>st;
    int n=s.length();
    for(int i=n-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch(s[i]){
                case '+':st.push(op1+op2);
                break;
                 case '-':st.push(op1-op2);
                break;
                 case '/':
                     st.push(op1/op2);
                     break;
                 case '*':
                     st.push(op1*op2);
                     break;
                 case '^':
                     st.push(pow(op1,op2));
                     break;
            }
        }
    }
    return st.top();
    
}
int postfixExpression(string s)
{
    stack<int> st;
    int n = s.length();
    for (int i = 0; i<n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}
void findnextgreatest(vector<int>&arr){
    int n=arr.size();
    stack<int>s;
    vector<int> v;

    //move from backward if search element is in right and  use reverse at last
    //move  forward if search element is in left and dont use reverse this time
    for(int i=n-1;i>=0;i--){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()>arr[i]){
            v.push_back(s.top());
        }
        else if(s.size()>0 && s.top()<=arr[i]){
            while(s.size()>0 && s.top()<=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }

        s.push(arr[i]);
    }


     reverse(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<" ";
    }

}


//store indexes of next greatest in right
void nearestSmallestinRight(vector<int> &arr)
{
    stack<pair<int, int>> s;
    vector<int> v;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(1);
        }
        else if (s.size() > 0 && s.top().first < arr[i])
        {
            v.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    reverse(v.begin(), v.end());
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < i)
        {
            ans.push_back(n);
        }
        else
        {
            ans.push_back(v[i]-i);
        }
    }
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        mx=max(mx,ans[i]*arr[i]);
    }
    cout<<mx<<endl;
    
}
int main(){
    //if s[0] is operator it is prefix and if s[n-1] is operator it is postfix expression
    // in post fix traverse left to rigtht aage se(because operator is in leftf side ) in code and when solvind handly put operator to the left of operands
    //in prefix fix traverse  rigtht to left peeche se (because operator is in right side ) in code and when solvind handly put operator to the right of operands
     
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    nearestSmallestinRight(v);

     //find next greatest or nearest larges to right




}