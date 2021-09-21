#include<bits/stdc++.h>
using namespace std;


struct node{
    public:
    int data;
    struct node*left;
    struct node*right;

};

struct node*constructtreehelper(int pre[],int*preindex,int key,int min,int max,int size);
struct node*constructree(int pre[],int size);
int search(int in[],int start,int end,int rootdata);
int isbst(struct node*root);

void preorder(struct node*root)
{
 if(root!=NULL)
  { cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);

  }

}

struct node*newnode(int data)
{

    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    
    return temp;
    }

/*

int search(int in[],int start,int end,int rootdata)
{
 int i;
 for(int i=start;i<=end;i++)
 {
     if(in[i]==rootdata)
     return i;
     break;
 }


}
*/
struct node*constructtreehelper(int pre[],int*preindex,int key,int min,int max,int size)
{
  if((*preindex)>size)
  return NULL;



struct node*root=NULL;
  if(key>min && key<max)
  {
   root=newnode(key);
   *preindex=*preindex+1;
      if(*preindex<size)
     { root->left=constructtreehelper(pre,preindex,pre[*preindex],min,key,size);
          root->right=constructtreehelper(pre,preindex,pre[*preindex],key,max,size); 
  }
  
  }

  return (root);

}

struct node*constructree(int pre[],int size)
{


    int preindex=0;
    return constructtreehelper(pre,&preindex,pre[0],INT_MIN,INT_MAX,size);
}

void inorder(struct node*root)
{



    if(root!=NULL)
    {

     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);

    }

}



    int main()
{


    int pre[]={10,5,1,7,40,50};

    int size=sizeof(pre)/sizeof(pre[0]);
    struct node*root=constructree(pre,size);

    cout<<" preorder traversal of bst is : \n";
    preorder(root);

       cout<<"\n  inorder traversal of bst is : \n";
    inorder(root);

}