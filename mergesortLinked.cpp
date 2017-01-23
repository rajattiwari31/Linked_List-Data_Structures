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
  while(head!=NULL){
    printf("%d\t" , head->data);
    head=head->next;
  }
  printf("\n");
}
struct node* merge_sortedList(struct node* a, struct node* b)
{
  struct node* headF=NULL;
  if(a==NULL)
      return(b);
  else if(b==NULL)
      return (a);
  if(a->data<=b->data)
  {
    headF=a;
    headF->next=merge_sortedList(a->next,b);
  }
  else
  {
    headF=b;
    headF->next=merge_sortedList(a,b->next);
  }
  return (headF);
}
void FrontBackSplit(struct node* temp, struct node** front_ref, struct node** back_ref)
{
  struct node* slow;
  struct node* fast;
  if((temp==NULL) || (temp->next==NULL))
      {
        *front_ref=temp;
        *back_ref=NULL;
      }
  else
  {
    slow=temp;
    fast=temp->next;
    while(fast!=NULL)
    {
      fast=fast->next;
      if(fast!=NULL)
      {
        slow=slow->next;
        fast=fast->next;
      }
    }
    *front_ref=temp;
    *back_ref=slow->next;
    slow->next=NULL;
  }
}
void merge_sort(struct node** headref)
{
   struct node* temp1=*headref;
   struct node* a;
   struct node* b;
   if((temp1==NULL)||(temp1->next==NULL))
   {
         return;
   }
   FrontBackSplit(temp1,&a,&b);

   merge_sort(&a);
   merge_sort(&b);

   *headref=merge_sortedList(a,b);
}
int main()
{
  struct node* head=NULL;
  push(&head,10);
  push(&head,9);
  push(&head,5);
  push(&head,20);
  push(&head,3);
  push(&head,223);
  push(&head,664);
  printf("LINKED LIST-\n");
  print(head);
  printf("SORTED Linked List is-\n");
  merge_sort(&head);
  print(head);
  return 0;
}
