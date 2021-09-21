#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;
vector<int> a(N);
vector<int>tree(4*N);
void update(int node,int st,int end,int idx,int value){
    if(st==end){
         a[idx]=value;
        tree[node]=value;

    }
    else{
        int mid=(st+end)/2;
        if(st<=idx && idx<=mid){
            update(2*node,st,mid,idx,value);
        }
        else{
            update(2 * node+1,mid+1,end, idx, value);
        }

        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
int  query(int node,int st,int end,int l,int r){
    //complete ,partial and no overalap


    //no overlap for sum return 0
    /*    end ... l ..... r... st .*/
    if(end<l || st>r){
        return 0;
    }

    //complete overlap
    //l  st end r
    if(l<=st && end<=r){
        return tree[node];
    }

    //partial overlap go to left and right both side
    // l.. st .r   en or   st...l.end....r
    
    int mid=(st+end)/2;


    int q1=query(2*node,st,mid,l,r);
    int q2=query(2*node+1,mid+1,end,l,r);


    return q1+q2;

}
void build (int node,int st,int end){
    if(st==end){
        tree[node]=a[st];
        return ;
    }
    int mid=(st+end)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);

    //this line changes
    tree[node]=tree[2*node+1]+tree[2*node];



}
signed main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    // 1 is root note

    while(q--){
        int c;
        cin>>c;
        if(c==2){
            int l,r;
            cin>>l>>r;
            cout<<query(1,0,n-1,l,r)<<endl;  //assume 0 base array indexing
        }
        else{
            int idx,val;
            cin>>idx>>val;
            update(1,0,n-1,idx,val);
        }


    }
}