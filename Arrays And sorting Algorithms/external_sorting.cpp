// quicksort is internal sorting but merge sort is external sorting
#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m, int r);
void mergesort(int a[], int l, int r);
void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1] = {};
    int R[n2] = {};
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = a[m + j + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    for (i; i < n1; i++)
        a[k++] = L[i];

    for (j; j < n2; j++)
        a[k++] = R[j];
}
void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    clock_t t;
    t = clock();

    mergesort(a, 0, n - 1);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printarray(a, n);
    cout<<"\n Time taken is "<<time_taken;
    return 0;
}