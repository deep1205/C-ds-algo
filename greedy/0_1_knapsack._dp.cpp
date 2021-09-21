#include<bits/stdc++.h>
using namespace std;
int max(int a,int b);
double knapsack(int val[],int wt[],int W,int n )
{
   int a[n+1][W+1];
   int i,w;

     for(i=0;i<n+1;i++)
     {
         for(w=0;w<W+1;w++)
         {
            if( i== 0 || w ==0)
            {a[i][w]=0;
         }
            else if(wt[i-1]<W)
                   {a[i][w] = max( 
                    val[i - 1] + a[i - 1][w- wt[i - 1]], 
                    a[i - 1][w]); 
                   }
            else
                a[i][w] = a[i - 1][w]; 
        } 
    } 
            
        
            

         
           
     

return a[n][W];

    
}

int max(int a,int b)
{
    return a>b? a:b;
}



int main()
{
 int w=50;
int value[]={60,100,120};
int weight[]={10,20,30};
int n=sizeof(value)/sizeof(value[0]);
cout<<"MAXIMum value of profit : "<<knapsack(value,weight,w,n);
    
}