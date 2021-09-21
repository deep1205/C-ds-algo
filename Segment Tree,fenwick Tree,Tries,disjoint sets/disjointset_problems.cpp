#include<bits/stdc++.h>

#define MAXN   100005

int par[MAXN], size[MAXN];
int rank[MAXN];
void init(int n)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        par[i] = i;
        size[i] = 1;
        rank[i]=1;
    }
}

int findParent(int idx)
{
    if(par[idx] == idx) return idx;
    return par[idx] = findParent(par[idx]);
}

void Union(int u, int v)
{
    int a = findParent(u);
    int b= findParent(v);

    if(a == b) return;

  
    if(rank[a]==rank[b]){
        rank[a]++;
        size[a]+=size[b];
        par[b]=a;
    }
    else if(rank[a]>rank[b]){
        par[b]=a;
        size[a]+=size[b];
        rank[b]=rank[a];
    }
    else{
        par[a]=b;
        size[b]+=size[a];
        rank[a]=rank[b];
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int i, j, k, n, q, idx;
    int u, v;
    char ch;

    scanf("%d %d", &n, &q);
    init(n);

    for(i = 1; i <= q; i++)
    {
        getchar();
        scanf("%c", &ch);

        if(ch == 'Q')
        {
            scanf("%d", &idx);
            printf("%d\n", size[findParent(idx)]);
            
              

        }
        else
        {
            scanf("%d %d", &u, &v);
            Union(u, v);
        }
    }
    return 0;
}