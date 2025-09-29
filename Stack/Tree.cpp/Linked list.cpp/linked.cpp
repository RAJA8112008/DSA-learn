#include<stdio.h>
#include<stdlib.h>
//doubly linked list
struct node{
  int data;
  struct node* next;
  struct node* prev;
};
void innsertAthead(struct node**head,int val){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->prev=NULL;
  newnode->data=val;
  newnode->next=*head;
  if(head!=NULL){
  (*head)->prev=newnode;
  }
  *head=newnode;
}
void insertattail(struct node* head,int val){
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=val;
   newnode->next=NULL;
   newnode->prev=NULL;
   if(*head==NULL){
    *head=newnode;
    return;
   }
   struct node* temp=head;
   while(temp->next!=NULL){
     temp=temp->next;
   }
   temp->next=newnode;
   newnode->prev=temp;

}
int main(){
 struct node* head=NULL;
}