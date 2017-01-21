#include<bits/stdc++.h>
using namespace std;
//finding length of linked list using iterative way;
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
void printCount(struct node* head)
{
  int count=0;
  struct node* temp=head;
  while(temp!=NULL){
    printf("%d\t" , temp->data);
    temp=temp->next;
    count++;
  }
  printf("\nTHe no. of node is : %d\n",count);
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
  printCount(head);
  return 0;

}
