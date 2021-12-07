#include <bits/stdc++.h>
using namespace std;
int vis[100001];

int sumofRepeatingElements(int m, int n, int **a)
{
    int mx = max(m, n);
    memset(vis, 0, sizeof(vis));
    int v[mx][mx];
    for (int i = 0; i < mx; i++)
    {
        for (int j = 0; j < mx; j++)
        {
            v[i][j] = 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i][j] = a[i][j];
        }
    }

    int zero = a[0][0];

    for (int i = 0; i < mx; i++)
    {
        for (int j = 0; j < mx; j++)
        {
            vis[v[i][j]] += 1;
        }
    }
    int s = 0;

    for (int i = 0; i < mx; i++)
    {
        for (int j = 0; j < mx; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < mx; i++)
    {
        if (vis[v[i][i]] > 1)
            s += v[i][i];
    }
    return s;
}
int main()
{
    int m, n;
    cin >> m >> n;

    int **array;
    array = new int *[m];
    for (int i = 0; i < m; i++)
        array[i] = new int[n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> array[i][j];
        }
    }

    cout << sumofRepeatingElements(m, n, array);
}