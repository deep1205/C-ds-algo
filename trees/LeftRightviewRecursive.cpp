#include <bits/stdc++.h>
using namespace std;
//recursive is better than iterative way for find view in leftt and right side
//time is O(n) and space complexity is O(height)

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
// time complexity is O(n) and space complexity is O(h)
void findleftview(Node *root, int level, vector<int> &left)
{
    //do preorder traversal
    if (root == NULL)
    {
        return;
    }

    if (level == left.size())
    {
        left.push_back(root->val);
    }
    findleftview(root->left, level+1, left);
    findleftview(root->right, level+1, left);
}
void leftview(Node *root)
{
    vector<int> left;
    int level = 0;
    findleftview(root, level, left);
    for (auto i : left)
    {
        cout << i << " ";
    }
}


/////////////////////////////////////////////////////////////
void findrightview(Node *root, int level, vector<int> &right)
{
    //do reverse preorder root right left
    if (root == NULL)
    {
        return;
    }

    if (level == right.size())
    {
        right.push_back(root->val);
    }
    findrightview(root->right, level+1, right);
    findrightview(root->left, level+1, right);
}
void rightview(Node *root)
{
    vector<int> right;
    int level = 0;
    findrightview(root, level, right);
    for (auto i : right)
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

    leftview(root); //do preorder if level==v.size() store root->val
    cout << endl;
    rightview(root);
}
