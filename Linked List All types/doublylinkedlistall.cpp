#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    struct node*next;
    struct node*prev;
};

void createlistatbeginning(struct node**head_ref,int newdata)
{
     struct node*tail;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));

   
    newnode->data = newdata;  
  
    newnode->next = (*head_ref);  
    newnode->prev = NULL;  
  
    if ((*head_ref) != NULL)  
        (*head_ref)->prev = newnode;  
  
    (*head_ref) = newnode;
}






void printlist(struct node*head)
{
    struct node*last;
    while(head!=NULL)
    {
      cout<<" " <<head->data;
      last=head;
      head=head->next;
    }
}
/*
void createlistatend(struct node**head_ref,int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;
    i
    n
-*/




int main()
{  
    struct node*head=NULL;
    createlistatbeginning(&head,7);
printlist(head);
cout<<"\n now addd 9 at front \n";
      createlistatbeginning(&head,9);
    printlist(head);

/*
    cout<<"\n now addd 1 at end \n";
      createlistatend(&head,9);
    printlist(head);*/
}