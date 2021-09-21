#include <bits/stdc++.h>
using namespace std;

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
bool isleaf(Node *node)
{
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return 0;
}
void addleftBoundary(Node *root, vector<int> &res)
{
    //going to left till left node is not  null if null go to right  and reach until root is not null
    Node *curr = root->left;
    while (curr)
    {
        if (!isleaf(curr))
        {
            res.push_back(curr->val);
        }

        if ((curr->left))
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void addrightBoundary(Node *root, vector<int> &res)
{
    //going to right till right node is not null if null go to left  and reach until root is not null
    vector<int> temp;
    Node *curr = root->right;
    while (curr)
    {
        if (!isleaf(curr))
        {
            temp.push_back(curr->val);
        }

        if ((curr->right))
        {
            curr = curr->right;
        }
        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}

void addleafNodes(Node *root, vector<int> &res)
{
    //do inorder //left root right if no
    if (isleaf(root))
    {
        res.push_back(root->val);
        return;
    }

    if (root->left)
        addleafNodes(root->left, res);
    if (root->right)
        addleafNodes(root->right, res);
}

void BoundaryTraversal(Node *root)
{
    //left subtree     leaf node(do inorder )    right subt in reverse order             --anticllockwise
    vector<int> res;
    if (root == NULL)
    {
        return;
    }

    if (!isleaf(root))
    {
        res.push_back(root->val); //store root
    }
    


    addleftBoundary(root, res);
    addleafNodes(root, res);
    addrightBoundary(root, res);

    for (auto i : res)
    {
        cout << i << " ";
    }
}
signed main()
{
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

    BoundaryTraversal(root);
}
