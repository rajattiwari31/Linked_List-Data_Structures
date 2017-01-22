#include<bits/stdc++.h>
using namespace std;
//Write a function to merge the two sorted linked list into one Sorted linked list;
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
  printf("\n");
}
void reverseList(struct node** head_ref)
{
  struct node* temp=*head_ref;
  struct node* prev=NULL;
  struct node* curr=temp;
  while(temp!=NULL)
  {
    temp=temp->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
  }
  *head_ref=prev;
}
void merge_sortedList(struct node* a, struct node* b)
{
  struct node* temp1=a;
  struct node* temp2=b;
  struct node* headF=NULL;
  while(temp1!=NULL && temp2!=NULL)
  {
    if(temp1->data >= temp2->data)
    {
      push(&headF,temp2->data);
      temp2=temp2->next;
    }
    else
    {
      push(&headF , temp1->data);
      temp1= temp1->next;
    }
  }
  if(temp1==NULL && temp2!=NULL)
  {
    while(temp2!=NULL)
    {
      push(&headF, temp2->data);
      temp2=temp2->next;
    }
  }
  else if(temp2==NULL && temp1!=NULL)
  {
    while(temp1!=NULL)
    {
      push(&headF, temp1->data);
      temp1= temp1->next;
    }
  }
  reverseList(&headF);
  printf("Merge 2 Sorted list is :");
  print(headF);
}
int main()
{
  struct node* head1=NULL;
  push(&head1,10);
  push(&head1,9);
  push(&head1,5);
  printf("Linked list 1-:\t");
  print(head1);
  struct node* head2=NULL;
  push(&head2,20);
  push(&head2,3);
  push(&head2,2);
  push(&head2,1);
  printf("Linked list 2-:\t");
  print(head2);
  merge_sortedList(head1,head2);

  return 0;

}
