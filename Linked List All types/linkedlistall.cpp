 
#include<bits/stdc++.h>
#define ll long long 
using namespace std;


class node{

    public:
    int data;
    node*next;
    node*prev;
};

void printlist(node*head)
{
    while(head!=NULL)
    {
        cout<<" "<<head->data;
        head=head->next;
    }
}

void insertatbeginning(node**head_ref,int newdata)
{  

    node*newnode=new node();
 newnode->data=newdata;
  newnode->next=*head_ref;
  *head_ref=newnode;

}

void insertatend(node**head_ref,int newdata)
{   

    node*temp=*head_ref;
    while((temp->next)!=NULL)
    {
        temp=temp->next;
    }

     node*newnode=new node();
       newnode->data=newdata;
       newnode->next=NULL;
       temp->next=newnode;

}

void insertatmid(node**head_ref,int newdata,int pos)
{
 int i=1;
node*newnode=new node();
node*temp=*head_ref;

while(i<pos)
    {
        temp=temp->next;
        i++;
    }

     
    newnode->data=newdata;
   newnode->next=temp->next;
     temp->next=newnode;

}

void deletefromfirst(node**head_ref)
{   
  node*temp=*head_ref;
   *head_ref=(*head_ref)->next;
    free(temp);
}

void deletefromend(node**head_ref)
{   
    node*temp=*head_ref;
    node*prevnode=temp;
    while(temp->next!=NULL)
    {   prevnode=temp;
        temp=temp->next;
    }
   
    free(temp);
    
      prevnode->next=NULL;
}


void deletefrompos(node**head_ref,int pos)
{
    node*temp=*head_ref;
    node*prevnode=temp;
    int i=1;
    while(i<pos)
    {   prevnode=temp;
        temp=temp->next;
        i++;
    }
    prevnode->next=temp->next;
    free(temp);
}

node* reverselist(node**head){
    node*curr=*head;
    node*prev=NULL;
    node*next;
    while(curr!=NULL){
        next = curr->next;
        curr->next=prev;
        
        prev=curr;
        curr=next;


    }
    return prev;

}
int main()

{ 



    clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
  node*head=NULL;

  head=new node();

  head->data=9;
  printlist(head);


cout<<"\n"<<"now we insert 7 at beginning ,list becomes \n";
insertatbeginning(&head,7);
printlist(head);

cout<<"\n"<<" now we insert 6 at end"<<"\n";
insertatend(&head,6);
printlist(head);
 

 cout<<"\n NOW, insert 3 i.e after  2nd given node 3rd position \n";
 insertatmid(&head,3,2);
 printlist(head);  


   node*newhead=reverselist(&head);
   cout<<endl;
   cout<<" Reverse Linked list is ";
   printlist(newhead);

//  cout<<"\n delete first node from beginning \n";
//  deletefromfirst(&head);
//  printlist(head);
 
//  cout<<"\n delete node after 9 i.e 2nd position \n";
//  deletefrompos(&head,2);
//  printlist(head);
 

 
//   cout<<"\n delete  node from end \n";
//  deletefromend(&head);
//  printlist(head);
 
// cout<<" TIME EXECUTION : "<<(double)(clock() - tStart)/CLOCKS_PER_SEC;
//    return 0;
}





 

