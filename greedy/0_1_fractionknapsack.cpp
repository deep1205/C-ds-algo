#include<bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and corresponding 
// value of Item 
struct Item 
{ 
    int value, weight; 
  
    // Constructor 
    Item(int value, int weight) : value(value), weight(weight) 
    {} 
}; 
  
// Comparison function to sort Item according to val/weight ratio 
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 

double fractionalKnapsack(int w,struct Item arr[],int n)
{
   sort(arr,arr+n,cmp);

   int currentw=0;
   double currentv=0.0;
   for(int i=0;i<n;i++)
   {
       if((currentw + arr[i].weight)<=w)
         {currentw+=arr[i].weight;
        currentv+=arr[i].value;
         }
        else
        {
            int remain=w-currentw;
             currentv+= arr[i].value * ((double) remain / arr[i].weight); 
            break;
        }
        
   }

   return currentv;



}


 // driver program to test above function 
int main() 
{ 
    int W = 50;   //    Weight of knapsack 
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n); 
    
} 
