#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl '\n'
#define M 1000000007

vector<int> answer(int n, vector<int> &val, vector<int> &parent)
{

    vector<int> res(n);
    vector<vector<int>> temp;
    vector<int> w;

    if (val[0] == 1)
        w.push_back(2);
    else
    {
        w.push_back(1);
        w.push_back(val[0]);
    }
    res[0] = w[0];
    temp.push_back(w);
    for (int i = 1; i < val.size(); i++)
    {

        int idx = parent[i - 1] - 1;
        w = temp[idx];
        int k = val[i];
        bool f = false;
        queue<int> q;
        for (auto j : w)
        {
            q.push(j);
        }
        while (!q.empty() && k == q.front())
        {
            q.pop();
            k++;
            f = true;
        }
        w.clear();
        while (!q.empty())
        {
            w.push_back(q.front());
            q.pop();
        }
        if (w.empty())
        {
            w.push_back(k);
        }
        else if (!w.empty() && find(w.begin(), w.end(), k) == w.end() && (f || w[0] < k))
        {
            w.push_back(k);
        }

        sort(w.begin(), w.end());
        temp.push_back(w);
        res[i] = w[0];
    }

    return res;
}

void solve()
{

    int n;
    cin >> n;
    vector<int> val(n);
    vector<int> parent(n - 1);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> parent[i];
    }
    vector<int> x = answer(n, val, parent);
    for (auto i : x)
    {
        cout << i << " ";
    }
    cout << endl;
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