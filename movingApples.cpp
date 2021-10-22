#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int average = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        average += v[i];
    }
    average /= n;
    int move = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > average)
        {
            move = move + (v[i] - average);
        }
    }
    cout << move;
}