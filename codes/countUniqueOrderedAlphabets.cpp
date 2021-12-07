
//count unique ordered Alphabets

#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl '\n'
#define M 1000000007

long long dp[100002][27];
long long count(string &a, string &b)
{
    long long m = a.size();
    long long n = b.size();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = ((dp[i - 1][j - 1]) % M + (dp[i - 1][j]) % M) % M;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}
int answer(int n, string s)
{
    string x = "abcdefghijklmnopqrstuvwxyz";
    return count(s, x);
}
void solve()
{

    int n;
    string s;
    cin >> n;
    cin >> s;
    cout << answer(n, s) << endl;
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
