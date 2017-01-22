#include<bits/stdc++.h>
using namespace std;
//Write a function to swap the two particular node in a linked list;
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
void swapNode(struct node** head_ref, int x, int y)
{
  struct node* prevx=NULL;
  struct node* prevy=NULL;
  struct node* tempx=*head_ref;
  struct node* tempy=*head_ref;
  //first we will search the data in the linked list
  if(x==y) return ;
  while(tempx!=NULL && tempx->data!=x)
  {
    prevx=tempx;
    tempx=tempx->next;
  }
  while(tempy!=NULL && tempy->data!=y)
  {
    prevy=tempy;
    tempy=tempy->next;
  }
  if(tempx==NULL || tempy==NULL)
        return ; //node is not prsent in the linked list;

  if(prevx!=NULL)
      prevx->next=tempy;
  else
      *head_ref=tempy;
  if(prevy!=NULL)
      prevy->next=tempx;
  else
      *head_ref=tempx;

  struct node* temp1=tempy->next;//it is use for SWAPPING the particular node;
  tempy->next=tempx->next;
  tempx->next=temp1;
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
  printf("\nlinked list after SWAPING 48 , 120 : \n");
  swapNode(&head,48,120);
  print(head);
  printf("\nlinked list after SWAPING 23 ,40  : \n");
  swapNode(&head,40,23);
  print(head);
  return 0;

}
