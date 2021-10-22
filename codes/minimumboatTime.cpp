
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int box[], int truck[],
                int n, int m, int min_time)
{
    int temp = 0;
    int count = 0;

    while (count < m)
    {
        for (int j = 0; j < min_time && temp < n && truck[count] >= box[temp];
             j += 2)
            temp++;

        count++;
    }
    if (temp == n)
        return true;

    return false;
}

int minTime(int box[], int truck[], int n, int m)
{

    sort(box, box + n);
    sort(truck, truck + m);

    int l = 0;
    int h = 2 * n;

    int min_time = 0;
    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (isPossible(box, truck, n, m, mid))
        {
            min_time = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }

    return min_time;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int box[n];
    int truck[m];
    for (int i = 0; i < n; i++)
    {
        cin >> box[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> truck[i];
    }

    printf("%d", minTime(box, truck, n, m));

    return 0;
}
