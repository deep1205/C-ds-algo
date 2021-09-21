#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace __gnu_pbds; 
using namespace std;

#define int           int64_t //store upto 10^18
#define S             second
#define F             first
#define pb            push_back
#define all(c)        (c).begin(),(c).end()
#define rall(c)       (c).rbegin(),(c).rend() 
#define lb            lower_bound
#define ub            upper_bound
#define si(c)         (int)((c).size())
#define lcm(a, b)      (a * (b / __gcd(a,b)))  
#define inf           (int)(1e9)
#define endl          '\n'
#define mp            make_pair
#define time(s)       (double(clock()-s)/double(CLOCKS_PER_SEC))
#define debug(args...)    _F(#args, args)
#define vi            std::vector<int>
#define pii           pair<int, int> 
#define vpi           vector<pii>
#define ordered_set   tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int64_t m=1000000007; 
clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
 
template<typename T> void _F(const char *name, T arg1){ cerr << name << " = " << arg1 << endl;}
template<typename T, typename... Args> void _F(const char *names, T arg1, Args... args)
{ const char *name = strchr(names, ',');cerr.write(names, name-names) << " = " << arg1 << endl;_F(name+2, args...);}
 
template< typename T1, typename T2 > istream& operator>>(istream& in, pair<T1, T2> &q){ in >> q.F >> q.S; return in;}
template< typename T1, typename T2 > ostream& operator<<(ostream& out, pair<T1, T2> &q){ out << q.F << " " << q.S; return out;}
template< typename T1, typename T2 > pair<T1, T2> operator+(pair<T1, T2> p1, pair<T1, T2> p2){ return {p1.F+p2.F, p1.S+p2.S};}
template< typename T1, typename T2 > pair<T1, T2> operator-(pair<T1, T2> p1, pair<T1, T2> p2){ return {p1.F-p2.F, p1.S-p2.S};}
template< typename T1, typename T2 > bool operator<(pair<T1, T2> p1, pair<T1, T2> p2){ return p1 < p2 ;}
 
template<typename T> void Unique(vector<T> &v) {
    sort(all(v)), v.resize(distance(v.begin(), unique(all(v))));
}
/////////////PREDEFINED USEFUL FUNCTION FOR FAST SOLVING  STARTS HERE////////
bool isprime(int n) {
    if (n == 1) {
        return false;
    }
    int i = 2;
    while (i*i <= n) {
        if (n % i == 0) {

            return false;
        }
        i += 1;
    }

    return true;
}
string decimalToBinary(int n) { 
    string s = bitset<64> (n).to_string(); 
    const auto loc1 = s.find('1'); 
    if(loc1 != string::npos) 
        return s.substr(loc1); 
        
    return "0"; 
} 
int countdigit(int n){
     return floor(log10(n)+1);
}
bool ispowerofn(int n,int base){
    return floor(log10(n)/log10(base))==(log10(n)/log10(base));
}
int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 }; 
int countSetBitsRec(int num) { 
    int nibble = 0; 
    if (0 == num) 
        return num_to_bits[0]; 
        
    nibble = num & 0xf; 
    return num_to_bits[nibble] + countSetBitsRec(num >> 4); 
} 
/////////////PREDEFINED USEFUL FUNCTION FOR FAST SOLVING  ENDS HERE////////
 /////////////  MAIN CODE STARTS HERE //////////////
 
 // Function to right-rotate an array by one position
void rightRotateByOne(vector<int>& A, int n)
{
    int last = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        A[i + 1] = A[i];
    }
 
    A[0] = last;
}

int upperbound(vector<int>&v,int ele){
    int n=v.size();
int low=0;
int high=n-1;
while(high-low>1){
    int mid=(low)+(high-low)/2;
    if(v[mid]<=ele){
        low=mid+1;
    }
    else{
        high=mid;
    }
}
if(v[low]>ele){
    return v[low];
    
}
else if(v[high]>ele){
    return v[high];
}
else
   return -1;
}


int lowerbound(vector<int>&v,int ele){
    int n=v.size();
int low=0;
int high=n-1;
while(high-low>1){
    int mid=(low)+(high-low)/2;
    if(v[mid]<ele){
        low=mid+1;
    }
    else{
        high=mid;
    }
}
if(v[low]>=ele){
    return v[low];
    
}
else if(v[high]>=ele){
    return v[high];
}
else
   return -1;
}


 //0-based indexing
int binarysearch(vector<int>&v,int ele){
    int n=v.size();
int low=0;
int high=n-1;
while(high-low>1){
    int mid=(low)+(high-low)/2;
    if(v[mid]<ele){
        low=mid+1;
    }
    else{
        high=mid;
    }
}
if(v[low]==ele){
    return low;
}
else if(v[high]==ele){
    return high;
}
else
return -1;
}
 

 //0-based indexing
int firstoccurence(vector<int>&v,int ele){
    int n=v.size();
int low=0;
int high=n-1;
int res=-1;
while(low<=high){
    int mid=(low)+(high-low)/2;
    if(v[mid]==ele){
        res=mid;
        high=mid-1;

    }
    else  if(v[mid]<ele){
        low=mid+1;
    }
    else
    {
        high=mid-1;
    }
}
return res;
}

 //0-based indexing
int lastoccurence(vector<int>&v,int ele){
    int n=v.size();
int low=0;
int high=n-1;
int res=-1;
while(low<=high){
    int mid=(low+high)/2;
    if(v[mid]==ele){
        res=mid;
        low=mid+1;
    

    }
    else if(v[mid]<ele){
        low=mid+1;
    }
    else
    {
        high=mid-1;
    }
}
return res;
}

 double epsilon=1e-7;
 
 double squareroot(int n){
     double low=1,high=n,mid;
     while(high-low>epsilon){
         mid=(low+high)/2;
         if(mid*mid<n){
             low=mid;
         }
         else
         {
             high=mid;
         }

 }
 return low;
 }



//calculate pow(a,b)%1e9+7 using binary search
 int64_t binaryexponentiation(int a,int b){
     int64_t ans=1;
     while(b){
         if(b&1){
             ans=(ans*a)%m;
         }
         a=a*a%m;
         b>>=1;
     }
     return ans%m;

 }
void solve() 
{   
  
int n,k;
cin>>n;
vector<int>v (n,0);
for(int i=0;i<n;i++){
    cin>>v[i];
}
cin>>k;
cout<<firstoccurence(v,k)<<" "<<lastoccurence(v,k)<<endl;
cout<<"count is "<<abs(lastoccurence(v,k)-firstoccurence(v,k))+1<<endl;


}
 //////////// MAIN CODE ENDS HERE ////
signed main() {
 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);   
    start = clock(); 
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif   
 
    int test = 1;
//    cin >> test;
 
    cout << fixed << setprecision(12);
     
    for(int i = 1; i <= test; ++i){
        solve();
    }
 
    cerr << time(start);
    return 0;
}