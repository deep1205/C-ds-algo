#include<bits/stdc++.h>
using namespace std;

struct node{

    public:
      int data;
    struct node*left;
    struct node*right;
};


int searchindex(int in[],int start,int inend,int data);
struct node*create(node);

struct node*create(int data)
{

 struct node*root=(struct node*)malloc(sizeof(struct node));
 root->data=data;
 root->left=NULL;
 root->right=NULL;

return (root);

}

struct node* buildtree(int in[],int pre[],int instart,int inend)
{
static int preindex=0;
 if(instart>inend)
 return NULL;

 struct node*root=create(pre[preindex++]);

 if(instart==inend)
 return root;


  int i=searchindex(in,instart,inend,root->data);
    
    root->left=buildtree(in,pre,instart,i-1);
    root->right=buildtree(in,pre,i+1,inend);

    return root;

 


}

int searchindex(int in[],int start,int inend,int data)
{
   int i;
   for(i=start;i<=inend;i++)
    { if(in[i] == data)
         return i;
        
    }
    

}
 void inorder(struct node*root)
{ 
 if(root==NULL)
     return ;

    inorder(root->left);
    cout<<root->data<<" ";
     inorder(root->right);

}

void postorder(struct node*root)
{
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main()
{
    

    int in[] = {7, 8, 4, 1, 6, 2, 5};  
    int pre[] = {1, 4, 7, 8, 2, 6, 5};  
    int len = sizeof(in) / sizeof(in[0]);  
   struct node*root=buildtree(in,pre,0,len-1);
cout<<" inorder traversal : \n";

   inorder(root);
   cout<<" \n postorder traversal : \n ";
   postorder(root);


    
}