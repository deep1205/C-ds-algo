#include <bits/stdc++.h>
using namespace std;
class DisjSet
{
  int *rank, *parent, n;

public:
  DisjSet(int n)
  {
    rank = new int[n];
    parent = new int[n];
    this->n = n;
    makeSet();
  }

  // Creates n single item sets
  void makeSet()
  {
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  // Finds set of given item x
  int find(int x)
  {
 
    if (parent[x] != x)
    {

      parent[x] = find(parent[x]);

      // so we recursively call Find on its parent
      // and move i's node directly under the
      // representative of this set
    }

    return parent[x];
  }

  // Do union of two sets represented
  // by x and y.
  void Union(int x, int y)
  {
    // Find current sets of x and y
    int xset = find(x);
    int yset = find(y);

    // If they are already in same set
    if (xset == yset)
      return;

    // Put smaller ranked item under
    // bigger ranked item if ranks are
    // different
    if (rank[xset] < rank[yset])
    {
      parent[xset] = yset;
    }
    else if (rank[xset] > rank[yset])
    {
      parent[yset] = xset;
    }

    // If ranks are same, then increment
    // rank.
    else
    {
      parent[yset] = xset;
      rank[xset] = rank[xset] + 1;
    }
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  queue<pair<int,int>> q;
  
  while (m--)
  {
    int a, b;
    cin >> a >> b;
  
    q.push(make_pair(a,b));

  }
  unordered_set<int> st;
  vector<int> d;
  queue<pair<int,int>> temp;

  while(!q.empty()){
       pair<int,int> p=q.front();
     q.pop();
    if(st.empty()){
      st.insert(p.first);
      st.insert(p.second);
    }
    else if(st.find(p.first)!=st.end() || st.find(p.second)!=st.end()){
      st.insert(p.first);
      st.insert(p.second);
    }
    else{
      temp.push(make_pair(p.first,p.second));
    }
    if(q.empty()){
      d.push_back(st.size());
      while(!temp.empty()){
        q.push(temp.front());
        temp.pop();
      }
      st.clear();
    }
  }
  /*
  int c=0;
 for(int i=0;i<n;i++)
 {
      if(obj.find(i)==obj.find(i+1))
      {
        c++;
      }
      else{
        d.push_back(c+1);
        c=0;
      }
 }
 int sum=accumulate(d.begin(),d.end(),0);
 int size=d.size();
 double mean=(double)(sum/size);
 double var=0;*/
 for(auto i:d)
 {
   cout<<i<<'\n';
 }
 //cout<<(double)var/size*size;
  
}