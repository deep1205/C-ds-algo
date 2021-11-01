#include<bits/stdc++.h>
using namespace std;
int64_t m=1e18;
int catalan[20]={0};
void getCatalanArray(){
    catalan[0] = 1;
    catalan[1] = 1;
    for (int i = 2; i < 20; i++)
    {
        int x = 0;
        int y = i - 1;
        int sum = 0;
        while (x < i && y >= 0)
        {
            sum = ((sum) % m + (catalan[x] * catalan[y]) % m) % m;
            x++;
            y--;
        }
        catalan[i] = sum;
    }
}
int main(){
  
  getCatalanArray();
  //Problems
  //1- number of structurally unique BST's (binary search trees)(or Number of labelled Trees) which has exactly n nodes of unique values from 1 to n
  //ans-catalan[n];


  //2-Number of unlablled binary trees ................
  //ans-(n!*catalan[n]);


  //3-No of ways to arrange Parenthesis(without letter)
  //ans-catalan[n];


  //4-No of dyck paths(no of ways to go from bottomm left to top right in n*n grid which lies above diagonal cells)
  //ans=catalan[n];;

  //5-no of ways to make dyck word of length n
//ans-catalan[n];

  //6-Number of ways a convex polygon of n+2 sides can split into triangles by connecting vertices
  //ans-catalan[n];


  //7-no of ways to connect 2*n point in a circle sucht that no two chhord are intersecting
  //ans-catalan[n];

  //8-
}