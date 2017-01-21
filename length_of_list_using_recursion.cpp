#include<bits/stdc++.h>
using namespace std;
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

int recLength(struct node* head)
{
  struct node* temp=head;
  if(temp==NULL)
      return 0;
  return(1+recLength(temp->next));
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
  printf("calculating length using recursion :-");
  int x=recLength(head);
  printf("%d\n", x);
  return 0;

}
