#include <bits/stdc++.h>
using namespace std;
// write in ascending order from left to right vertical and top to bottom 
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};
void verticalTraversal(Node*root){
    map<int,map<int,multiset<int>>>nodes; 
    /*every vertical have level ahd each level has multinodes with
    int for vertical
    int for level with vertical
    multiset for multinode at level of vertical*/
    /*queue store root,vertical,level*/
    
    queue<pair<Node*,pair<int,int>>> todo;
    //now do level order 
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        Node*node=p.first;
        int x=p.second.first;
        int y=p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left){
            todo.push({node->left, {x-1, y+1}});
        }

        if(node->right)
        {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }
   

   vector<vector<int>>ans;
   for(auto i:nodes){
       vector<int>col;
       for(auto q:i.second){
           //iinsert all multiset elements at the end of vector
           col.insert(col.end(), q.second.begin(), q.second.end());
       }
       ans.push_back(col);
   }


   for(auto i:ans){
       for(auto j:i){
           cout<<j<<" ";
       }
       cout<<endl;
   }

}

signed main()
{    

            /*      1
             2            7
        3                    8
          4              9
        5   |  6        10     11
                  


            
             
                                      */
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->right->right = new Node(8);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);

    verticalTraversal(root);
}
