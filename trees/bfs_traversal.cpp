#include<bits/stdc++.h>
using namespace std;

template<typename T> 
class graph
{
    map<T,list<T>> m;
    public :
    void addEdge(int x,int y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }  
    
//      void dfs()
//      [

//   map<T,int> visited;




//      ]
    void bfs(T src)
    {
        map<T,int> visited;
    queue<T> q;
      q.push(src);
      visited[src]=true;
        while(!q.empty())
        {

            T node=q.front();
        q.pop();
        cout<<node<<" ";
           for(int nbr:m[node])
           { if(!visited[nbr])
            q.push(nbr);


            visited[nbr]=true;

           }

        }

    }
};

int main()
{

    graph<int> g;
 g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout <<"Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.bfs(2); 
  
    return 0; 
} 