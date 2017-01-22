#include<bits/stdc++.h>
using namespace std;
//Write a function to reverse a linked list;
struct node{
  int data;
  struct node* next;
};
void push(struct node** head_ref, int key)
{
  struct node* newnode = (struct node* )malloc(sizeof(struct node));
  newnode->data=key;
  newnode->next=*head_ref;
  *head_ref=newnode;
}
void print(struct node* head)
{
  if(head==NULL)
      printf("NULL\n");
  struct node* temp=head;
  while(temp!=NULL){
    printf("%d\t" , temp->data);
    temp=temp->next;
  }
}
void reverseList(struct node** head_ref)
{
  struct node* temp=*head_ref;
  struct node* prev= NULL;
  struct node* curr=temp;
  while(curr!=NULL)
  {
    curr=curr->next;
    temp->next=prev;
    prev=temp;
    temp=curr;
  }
  *head_ref=prev;

}

int main()
{
  struct node* head=NULL;
  push(&head,40);
  push(&head,52);
  push(&head,48);
  push(&head,47);
  push(&head,42);
  push(&head,120);
  push(&head,23);
  print(head);
  printf("\nREversed linked list is :\n");
  reverseList(&head);
  print(head);
  return 0;

}
