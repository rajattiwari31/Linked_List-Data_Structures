#include<bits/stdc++.h>
using namespace std;

struct node{
   int data;
   struct node* next;
};

void push(struct node** head_ref,int key)
{
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=key;
   newnode->next=*head_ref;
   struct  node* temp=*head_ref;
   if(*head_ref!=NULL)
    {
      while(temp->next!=*head_ref)
          temp=temp->next;
      temp->next=newnode;
    }
    else
        newnode->next=newnode;
    *head_ref=newnode;
}
void print(struct node* head)
{
  if(head==NULL)
    printf("NULL");
  struct node* temp= head;

  do
  {
    printf("%d\t",temp->data);
    temp=temp->next;
  }
  while(temp!=head);
}
int main() {
  struct node* head=NULL;
  push(&head,10);
  push(&head,8);
  push(&head,5);
  push(&head,2);
  print(head);
  printf("\n");
  return 0;
}
