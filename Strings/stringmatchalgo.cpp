#include<iostream>
using namespace std;
void getZarray(string total,int z[]);
void search(string s,string p)
{
    string total=p+"$"+s;
    int x=total.length();
    int z[x];
    getZarray(total,z);
    for(int i=0;i<x;i++)
    {
        if(z[i]==p.length())
        {
            cout<<"pattern found at "<<i-p.length()-1<<endl;
        }
    }
}

void getZarray(string total,int z[])
{
    int l,r;
    l=0;
    r=0;
    int n=total.length();
    for(int i=1;i<n;i++)
    {
        if(i>r)
        {
            l=i;
            r=i;
            while(r<n && total[r-l]==total[r])
            
                r++;
                z[i]=r-l;
                r--;
            

        }
        else
        {
            int idx=i-l;
            if(z[idx]<r-i+1)
            {
                z[i]=z[idx];
            }
            else
            {
                l=i;
                while(r<n && total[r-l]==total[r])
                
                    r++;
                    z[i]=r-l;
                    r--;
                
            }
            
        }
        
    }
}
int main()
{
    string s;
    string p;
    cin>>s>>p;
    search(s,p);
    return 0;

}