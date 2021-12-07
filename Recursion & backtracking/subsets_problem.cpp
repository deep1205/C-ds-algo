
#include <bits/stdc++.h>
using namespace std;
vector<int> res;

//print all subsequences withut duplicates
void method2(int index, vector<int> &v, vector<vector<int>> &ans, vector<int> &arr)
{
    ans.push_back(v);
    for (int i = index; i < arr.size(); i++)
    {
        // if there are two element with different index but same value 1 2 2 we only pick 1 2 so we dont pick it and continue
        if (i != index && arr[i] == arr[i - 1])
            continue;

        v.push_back(arr[i]);
        method2(i + 1, v, ans, arr);
        v.pop_back();
    }
}

//printallsubsequence with duplicates
void method1(int index, vector<int> &v, vector<vector<int>> &ans, vector<int> &arr)
{
    ans.push_back(v);
    for (int i = index; i < arr.size(); i++)
    {
        v.push_back(arr[i]);
        method1(i + 1, v, ans, arr);
        v.pop_back();
    }
}
void subsetsum(vector<int> arr, int N)
{
    sort(arr.begin(), arr.end());
    // Write Your Code here
    vector<int> v;
    vector<vector<int>> res;

    //print subsequence with duplicates
    // method1(0,v,res,arr);

    //printsubsequence without duplicates
    method1(0, v, res, arr);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    subsetsum(v, n);
    sort(res.begin(), res.end());
   
}