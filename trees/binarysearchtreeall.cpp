#include<bits/stdc++.h>
using namespace std;
struct node{

public:
int key;
node*left;
node*right;
};


/*prototype declaration*/
struct node*insert(struct node*root,int key);
struct node*newnode(int key);

struct node* searchkey(struct node*root,int key);

struct node*newnode(int key)
{

    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
    
}

struct node*insert(struct node*root,int key)
{

if(root==NULL)
return newnode(key);

if(key>(root->key))
  root->right =insert(root->right,key);
  else if(key<(root->key))
    root->left=insert(root->left,key);
  
  return root;



}
void inorder(struct node*root)
{

    if(root!=NULL)
{
  inorder(root->left);
  cout<<root->key<<" ";
  inorder(root->right);
}
}

struct node* searchkey(struct node*root,int key)
{
 if(root == NULL || ((root->key)==key))
     return root;

     if(key>root->key)
     return searchkey(root->right,key);
    else if(key<root->key)
     return searchkey(root->left,key);



    return root;





  
}
int main()
{



    struct node*root=NULL;
   root= insert(root,8);
     insert(root,2);
      insert(root,3);
    insert(root,6);
   insert(root,5);
   insert(root,4);
   insert(root,7);
   insert(root,1);


           cout<<" INORDER traversal of a binary search tree : \n";
           inorder(root);
    
    
     struct node*newnode=searchkey(root,6);
    struct node*nextnewnode=searchkey(root,9);

  if(newnode!=NULL)
  {cout<<" \n key found and value is"<<newnode->key<<" and address is "<<newnode;

  cout<<" \n key found and value is"<<nextnewnode->key<<" and address is "<<nextnewnode;
  }
  else
  {
    cout<<"\n  key not found";
  }
  
           return  0;


}
