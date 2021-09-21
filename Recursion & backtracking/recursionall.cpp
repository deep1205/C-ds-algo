#include<bits/stdc++.h>
using namespace std;

int k=2;
// subset is dis-continuous while subarray us continious 
void printsubsetsumk(int index,int sum,vector<int>&ans,vector<int>&arr){
    if(index==arr.size()){
        if(ans.size()!=0 && sum%k==0){
            cout<<ans.size()<<endl;
            for (auto i : ans)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else{
            cout<<-1<<endl;
        }
      
        return ;

    }

    //pick up
    ans.push_back(arr[index]);
    sum+=arr[index];
    printsubsetsumk(index + 1, sum,ans, arr);

    //not pick up
    ans.pop_back();
    sum-=arr[index];
    printsubsetsumk(index+1,sum,ans,arr);


  

}
//////////////////////////////////////////////////////////////////////////////////
int countsubsetsumdivisiblek(int index, int sum, vector<int> &ans, vector<int> &arr)
{

    if (index == arr.size())
    {
        if (ans.size() != 0 && sum % k == 0)
        {
            return 1;
        }

        return 0;
    }

    ans.push_back(arr[index]); //pick up
    sum += arr[index];
    int leftrecursion=countsubsetsumdivisiblek(index + 1, sum, ans, arr);
    ans.pop_back(); //not pick up
    sum -= arr[index];
    int rightrecursion=countsubsetsumdivisiblek(index + 1, sum, ans, arr);
    return leftrecursion+rightrecursion;
}

///////////////////////////////////////////////////////////////////////


int countsubsetswithsumkrepetitionallowed(int index,int sum,vector<int>&ans,vector<int>&arr){
if(arr.size()==index ){
    return sum==0?1:0;
}
int left=0;
int right=0;
if(arr[index]<=sum){
    sum-=arr[index];
  left= countsubsetswithsumkrepetitionallowed(index,sum,ans,arr);
sum+=arr[index];
}
right=countsubsetswithsumkrepetitionallowed(index+1,sum,ans,arr);

return left+right;


}
///////////////////////////////////////////////////////////////

void printsubsets(int index,int sum,vector<int>&ans,vector<int>&arr){
    if(index==arr.size()){
        if(sum==0){
            for(auto i:ans){
                cout<<i<<" ";
            }
            
            cout<<endl;

        }
        return ;
    }

//we pick an element
    if(arr[index]<=sum){
        ans.push_back(arr[index]);
        sum-=arr[index];
        printsubsets(index,sum,ans,arr);
        //in case if repetiton is not allowed use printsubsets(index+1,,sum,ans,arr);
        sum+=arr[index];
        ans.pop_back();
    }
//not pick an element
    printsubsets(index+1,sum,ans,arr);
    
}
int main(){
    vector<int> arr={1,2,3,4,8};
    vector<int> ans;
    printsubsetsumk(0, 0, ans,arr);//repetition not allowed
    //countsubsetsumdivisiblek(0,0,ans,arr);
    int sum=4;
    //cout<<countsubsetswithsumkrepetitionallowed(0,sum,ans,arr)<<endl;//repetition allowed

    //printsubset with sum k repetition alllowed
   // printsubsets(0,sum,ans,arr);
    


}