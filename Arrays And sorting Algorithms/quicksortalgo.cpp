#include <bits/stdc++.h>
using namespace std;

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

//fastest sorting algo with time complexity O(nlogn) in best and average case

//partiion give index of pivot element at a proper position
int Partition(int a[], int lb, int ub)
// lb=lower bound,ub=upper bound

{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }

        if (start < end)
            swap(a[start], a[end]);
    }

    swap(a[lb], a[end]);
    return end;
}
void quicksort(int a[], int lb, int ub)
{
    if (lb < ub)
    {

        int pivotindex = Partition(a, lb, ub);

        quicksort(a, lb, pivotindex - 1);
        quicksort(a, pivotindex + 1, ub);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n] = {};
    // how to find size
    // n=sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    quicksort(a, 0, n - 1);
    printarray(a, n);
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculating total time taken by the program.
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

    cout << "\n Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    return 0;
}