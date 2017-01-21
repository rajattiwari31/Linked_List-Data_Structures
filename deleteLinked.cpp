#include<bits/stdc++.h>
using namespace std;
void deletenode(struct node** head_ref , int pos);
struct node{
int data;
struct node* next;
};

void insertHead(struct node** head_ref , int key)
{
   struct node* newnode= (struct node*)malloc(sizeof(struct node));
   newnode->next = *head_ref;
   newnode->data=key;
   *head_ref=newnode;

}
void insertAfter(struct node *head, int key, int pos)
{
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  struct node* temp =  head;
  struct node* prev = NULL;
  int h=0;
  newnode->data=key;
  while(h<pos-1)
  {
    prev=temp;
    temp = temp->next;
    h++;
  }
  newnode->next=prev->next;
  prev->next=newnode;
}
void insertEnd(struct node** head_ref, int key)
{
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=key;
  struct node* temp=*head_ref;
  if(temp==NULL)
      {
          newnode->next=NULL;
          temp=newnode;
      }
   while(temp->next!=NULL)
   {
     temp =temp->next;
   }
   temp->next=newnode;
   newnode->next=NULL;
}
void printLinked(struct node* head)
{
  while(head!=NULL)
  {
    printf("%d\t\n",head->data );
    head= head->next;
  }
}
void deletenode(struct node** head_ref , int pos)
{
  int h=0;
  if(*head_ref==NULL)
      printf("Linked list is empty\n");
  struct node* temp=*head_ref;
  struct node* prev=NULL;
  if(pos==1)
  {
    *head_ref=temp->next;
    free(temp);
    return ;
  }
  while(h<pos-1)
  {
    prev= temp;
    temp=temp->next;
    h++;
  }
  prev->next=temp->next;
  temp->next=NULL;
  free(temp);
}

int main()
{
  struct node* head=NULL;
  insertHead(&head, 10);
  insertHead(&head , 5);
  insertEnd(&head , 20);
  insertEnd(&head , 40);
  insertAfter(head , 30 ,2);
  insertAfter(head , 80 ,4);
  printLinked(head);
  printf("deleting node at postion 3: \n");
  deletenode(&head,3);
  printLinked(head);

  printf("deleting node at postion 1: \n");
  deletenode(&head,1);
  printLinked(head);

  printf("deleting node at postion 4: \n");
  deletenode(&head,4);

  printLinked(head);
  return 0;
}
