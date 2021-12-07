#include<bits/stdc++.h>
using namespace std;
long long int ASCIIWordSum(string str,
                          vector<long long int>& sumArr)
{
 
    int l = str.length();
    int sum = 0;
    long long int bigSum = 0L;
    for (int i = 0; i < l; i++) {
 
     
        if (str[i] == ' ') {
 
            bigSum += sum;
            sumArr.push_back(sum);
            sum = 0;
        }
        else
 
          
            sum +=  str[i];       
    }
 
  
    sumArr.push_back(sum);
    bigSum += sum;
    return bigSum;
}
//
int main(){
	string str;
	getline(cin,str);
    vector<long long int> sumArr;
 
    long long int sum = ASCIIWordSum(str, sumArr);
 
    
   
    cout << "Sum of all characters is " << sum;
    return 0;
}