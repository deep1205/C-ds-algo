#include <bits/stdc++.h>
using namespace std;
// all are examples of internal sorting where no extra space is needed
  void insertionsort(int a[], int n);
void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void selectionsort(int a[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
            swap(a[min], a[i]);
        }
    }
}
    void insertionsort(int a[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] < a[j])
                    swap(a[i], a[j]);
            }
        }
    }
    void bubblesort(int a[],int n)// use adjacent swapping only
    {   bool swapexist;
        for(int i=0;i<n-1;i++)
        {    
            for(int j=0;j<n-i-1;j++)
            
            {     swapexist=false;
                if(a[j]>a[j+1])
                  swap(a[j],a[j+1]);
                swapexist=true;
            }
            if(swapexist==false)
            break;
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
    // selectionsort(a,n);
    // insertionsort(a, n);
    // printarray(a, n);
      struct timespec start, end; 
  
    clock_gettime(CLOCK_MONOTONIC, &start);
    bubblesort(a,n);
        
    printarray(a,n);
    //calculate execution time
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