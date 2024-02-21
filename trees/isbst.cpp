#include<bits/stdc++.h>
using namespace std;
 


 struct node{

     public:
     int data;
     struct node*left;
     struct node*right;
     
       node(int data)
       {
           this->data=data;
           this->left=NULL;
           this->right=NULL;
       }
     
      };


int isbstfinder(struct node*root,int min,int max)
{
 if(root==NULL)
 return 1;


 if(root->data<min  || root->data>max)
 return 0;

 return 
 isbstfinder(root->left,min,root->data+1) && 
 isbstfinder(root->right,root->data+1,max);



}

int isbst(struct node*root)
{
 return isbstfinder(root,INT_MIN,INT_MAX);
}
      int main()
      {
  
   freopen("output.txt", "w", stdout);


          struct node*root=NULL;
    root = new node(3);  
    root->left = new node(2);  
    root->right = new node(5);  
    root->left->left = new node(1);  
    root->left->right = new node(4);  
      


      if(isbst(root))
      cout<<"\n IT IS BINARY TREE";
      else
      {
          cout<<"\n NOT A BINARY TREE";
      }
      
      }