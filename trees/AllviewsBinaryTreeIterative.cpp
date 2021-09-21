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
// time complexity is O(n) and space complexity is O(n)
vector<vector<int>> levelordertraversal(Node *root)
{
    vector<vector<int>> v;
    if (root == NULL)
    {
        return v;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *topnode = q.front();
            q.pop();
            if (topnode->left != NULL)
                q.push(topnode->left);
            if (topnode->right != NULL)
                q.push(topnode->right);

            level.push_back(topnode->val);
        }
        v.push_back(level);
    }

   return v;
}

// time complexity is O(n*logn)[logn for insert inito multiset] and space complexity is O(n)+O(n)
vector<vector<int>> verticalorderTraversal(Node *root)
{
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        Node *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val);
        if (node->left)
        {
            todo.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }

    for (auto i : nodes)
    {
        vector<int> col;
        for (auto j : i.second)
        {
            col.insert(col.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
void Topview(Node *root)
{

    //Your code here
    // store first node of each vertical from top to bottomv
    vector<vector<int>> ans = verticalorderTraversal(root);

    vector<int> res;
    for (auto i : ans)
    {
        res.push_back(i[0]);
    }

    for (auto i : res)
    {
        cout << i << " ";
    }
}

void Bottomview(Node*root){
    //store last node of each vertical 
    vector<int>res;
    vector<vector<int>>ans=verticalorderTraversal(root);
    for(auto i:ans){
          int n=i.size();
          res.push_back(i[n-1]);


    }
    
    for(auto i:res){
        cout<<i<<" ";
    }
}

void leftview(Node*root){
    vector<vector<int>> ans =levelordertraversal(root);

    vector<int> res;
    for (auto i : ans)
    {
       
        res.push_back(i[0]);
    }

    for (auto i : res)
    {
        cout << i << " ";
    }
}
void rightview(Node*root){
    vector<vector<int>> ans = levelordertraversal(root);

    vector<int> res;
    for (auto i : ans)
    {
          int n=i.size();
        res.push_back(i[n-1]);
    }

    for (auto i : res)
    {
        cout << i << " ";
    }
}
signed main()
{

    /*             1
             2           7
        3                    8
          4              9
        5   | 6    10         11
                 


            
             
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
    //remember in vertical order we traverse top to bottom and in level we traverse left to right



    Topview(root); 
    cout<<endl;      //(vertical order traversal ki first node)
    Bottomview(root);
    cout << endl;         //(vertical order traversal ki last node)
    leftview(root);
    cout << endl;         //(level order traversal ki first node)
    rightview(root);
    cout << endl; // (level order traversal ki last node)
}
