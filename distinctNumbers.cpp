#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl '\n'
#define M 1000000007

void solve()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back(v[i]);
    }
    sort(temp.begin(), temp.end());
    int l = 0;
    int r = n - 1;
    vector<tuple<int, int, int>> x;
    int shift = 0;
    while (l <= r)
    {
        if (v[l] != temp[l])
        {
            int findIndex = find(v.begin(), v.end(), temp[l]) - v.begin();

            int diff = findIndex - l;
            rotate(v.begin() + l, v.begin() + (diff % n), v.end());
            shift++;
            x.push_back(make_tuple(l + 1, n, diff));
        }
        l++;
    }
    cout << shift << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
