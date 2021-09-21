#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 2;
vector<int> a(N);
vector<pair<int,int>> tree(4 * N);
void update(int node, int st, int end, int idx, int value)
{
    if (st == end)
    {
        a[idx]= value;
        tree[node].first= value;
        tree[node].second=1;
        return ;
    }
    else
    {
        int mid = (st + end) / 2;
        if (st <= idx && idx <= mid)
        {
            update(2 * node, st, mid, idx, value);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, idx, value);
        }

        if (tree[2 * node].first < tree[2 * node + 1].first)
        {
            tree[node].first = tree[2 * node].first;
            tree[node].second = tree[2 * node].second;
        }
        else if (tree[2 * node + 1].first < tree[2 * node].first)
        {
            tree[node].first = tree[2 * node + 1].first;
            tree[node].second = tree[2 * node + 1].second;
        }
        else
        {
            tree[node].first = tree[2 * node].first;
            tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
        }
    }
}
pair<int,int>query(int node, int st, int end, int l, int r)
{
    //complete ,partial and no overalap

    //no overlap for sum return 0
    /*    end ... l ..... r... st .*/
    if (end < l || st > r)
    {   
        return {INT_MAX,-1};  //ekdum opposite return kro

    }

    //complete overlap
    //l  st end r
    if (l <= st && end <= r)
    {
        return {tree[node].first,tree[node].second};
    }

    //partial overlap go to left and right both side
    // l.. st .r   en or   st...l.end....r

    int mid = (st + end) / 2;

    pair<int,int> q1 = query(2 * node, st, mid, l, r);
pair<int,int> q2 = query(2 * node + 1, mid + 1, end, l, r);
pair<int,int>q;
    if(q1.first<q2.first){
        q=q1;
    }
    else if(q2.first<q1.first){
        q=q2;
    }
    else{
        q.first=q1.first;
        q.second=q1.second+q2.second;
    }
    return q;
}
void build(int node, int st, int end)
{
    if (st == end)
    {   tree[node].first=a[st];
        tree[node].second=1;
        return;
    }
    int mid = (st + end) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, end);

    //this line changes
    // chote ko lelo if barabar then first m kisi k bhi daaldo but add frequency in both
    if(tree[2*node].first<tree[2*node+1].first){
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second;

    }
    else if(tree[2*node+1].first<tree[2*node].first){
        tree[node].first = tree[2 * node+1].first;
        tree[node].second = tree[2 * node + 1].second;
    }
    else{
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second+tree[2*node+1].second;
    }
}

signed main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    // 1 is root note

    while (q--)
    {
        int  c;
        cin >> c;
        if (c == 2)
        {
            int l, r;
            cin >> l >> r;
            pair<int,int>ans=query(1,0,n-1,l,r-1);
            cout<<ans.first<<" "<<ans.second<<endl;

        }
        else if(c==1)
        {
            int idx, value;
            cin >> idx >> value;
            update(1, 0, n - 1, idx , value);
        }
    }
}