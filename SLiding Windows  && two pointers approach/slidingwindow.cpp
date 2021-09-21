#include<bits/stdc++.h>
using namespace std;

int windowsum(int a[],int n,int k)
{
  int wsum=0,maxsum=0;

 for(int i=0;i<k;i++)
 {
    wsum+=a[i];
 }
 for(int i=k;i<n;i++)
  { wsum=wsum+a[i]-a[i-k];
   maxsum=max(wsum,maxsum);
  }
  return maxsum;
}
int main()
{

int t;
cin>>t;
while(t--)
{

    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }

    cout<<windowsum(a,n,k);

}


}