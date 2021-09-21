#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int64_t m = 1e9 + 7;
int64_t add(int64_t x, int64_t y)
{
    if (y == 0)
        return x;
    else
        return add(x ^ y, (unsigned)(x & y) << 1);
}

int64_t subtract(int64_t x, int64_t y)
{
    if (y == 0)
        return x;
    return subtract(x ^ y, (~x & y) << 1);
}

int64_t power(int64_t a, int64_t b)
{ int64_t ans = 1;
    while (b)
    { if (b & 1) {
            ans = (ans * a) % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans % m;
}
int64_t multiply(int64_t a,int64_t b)
{
    int64_t res = 0; 
    a %= m;
    while (b)
    {
        if (b & 1){
            res = (res + a) % m;
        } 
        a = (2 * a) % m;
        b >>= 1;
    }

    return res;
}
int64_t squareRoot(int64_t x)
{
    
    if (x == 0 || x == 1)
        return x;
    int start = 1, end = x, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid * mid == x)
            return mid;
        if (mid <= x / mid){
            start = mid + 1;
            ans = mid;
        }
        else 
            end = mid - 1;
    }
    return ans;
}
signed main(){
    int64_t a,b;
    cin>>a>>b;
//a and b is large numbers calculate all under modulo 19+7
//over flow occurs if our answer is more than 10^18
    cout<<a+b<<endl;
    cout<<subtract(a,b)<<endl;



    cout<<multiply(a,b)<<endl;
    cout<<power(a,b)<<endl;
    cout<<squareRoot(a)<<endl;
}