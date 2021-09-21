#include <bits/stdc++.h>
using namespace std;
// top and bottom do iterative way time complexity iso(n) and space is O(n)
// do level order traversal
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
void Topview(Node *root){
if(root==0){
            cout<<"empty tree";
        }
        map<int,int>mp;             //(line,node value)
        queue<pair<Node*,int>>q;   //(node,line)
        //Your code here
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                 Node*node=it.first;
                 int line =it.second;
                 if(mp.find(line)==mp.end()){
                     mp[line]=node->val;
                 }
                 
                 if(node->left!=NULL){
                     q.push({node->left,line-1});
                 }
                 if(node->right!=NULL){
                     q.push({node->right,line+1});
                 }
            }
        }
        
        for(auto it:mp){
            cout<<it.second<<" ";
        }
}
void Bottomview(Node *root){
    if(root==0){
            cout<<"empty tree";
        }
        map<int,int>mp;             //(line,node value)
        queue<pair<Node*,int>>q;   //(node,line)
        //Your code here
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                 Node*node=it.first;
                 int line =it.second;
                
                     mp[line]=node->val;
                 
                 
                 if(node->left!=NULL){
                     q.push({node->left,line-1});
                 }
                 if(node->right!=NULL){
                     q.push({node->right,line+1});
                 }
            }
        }
        
        for(auto it:mp){
            cout<<it.second<<" ";
        }
    //

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

    Topview(root); //do preorder if level==v.size() store root->val
    cout << endl;
    Bottomview(root);
}
