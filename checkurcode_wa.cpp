#include<bits/stdc++.h>
using namespace std;
#define int int64_t
//-----------------write correct solution/brute--- force here----/

int correctsolution(vector<int>&arr,int n){
return 2;
}




//-----------------write correct solution/brute--- force here----/
//-----------------------------------------------------------------------------//
//-----------------write Your solution here/optimised once----/

int mysolution(vector<int>&arr,int n){
    return 1;
}



//-----------------write your solution  here----/

signed main(){
    srand(time(NULL));//so that each time rand give different number
    int testcase=1;
    while(testcase<90){
      ///asssume we taken input n and  n size array

        int n=rand()%5+1;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=rand()%10+1;
        }

        int correctans=correctsolution(arr,n);
        int myans=mysolution(arr,n);
        if(correctans!=myans){
            cout<<n<<endl;
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<"Your ans is "<<myans<<endl;
            cout<<"Correct ans is "<<correctans<<endl;
            cout<<endl;
        }
        testcase++;



    }


}