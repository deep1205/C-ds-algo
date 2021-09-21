#include<bits/stdc++.h>
using namespace std;
#define int long long 

struct Node{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int value){
       data=value;
       left=NULL;
       right=NULL;
    }
};


void preorder(Node*root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    
    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}
void levelordertraversal(Node*root){
    vector<vector<int>>v;
    if(root==NULL){
        cout<<"Empty Tree";
        return ;
    }

    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node* topnode=q.front();
            q.pop();
            if(topnode->left!=NULL)q.push(topnode->left);
            if (topnode->right != NULL) q.push(topnode->right);

            level.push_back(topnode->data);          
            }
            v.push_back(level);
    }

    for(auto i:v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

signed main(){

struct Node*root=new Node(3);
root->left=new Node(9);
root->right=new Node(20);
root->right->left=new Node(15);
root->right->right=new Node(7);


//Traversals 
levelordertraversal(root);
cout<<endl;
preorder(root);
cout <<endl;
postorder(root);
cout << endl;
inorder(root);

}