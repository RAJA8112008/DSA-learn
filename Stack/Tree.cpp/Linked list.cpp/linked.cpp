#include<stdlib.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
};
//ccircular linked list
void insertAtEnd(struct node* head,int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=NULL;
  if(*head==NULL){
    *head=newnode;
  }
  struct node*temp=head;
   while(temp->next!=head){
    temp=temp->next;
   }
   temp->next=newnode;
   newnode->next=*head;
}
int main(){
  struct node* head=NULL;
}