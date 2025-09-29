#include<stdio.h>
#include<stdlib.h>
struct node{
  int  data;
  struct node* next;
};
void insertAthead(struct node** head,int data){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
  }
  //insert at end
  void insertAtend(struct node**head,int data){
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL){
      *head=newnode;
      return;
    }
    struct node* temp=*head;
      while(temp->next!=NULL){
        temp=temp->next;
        temp->next=newnode;
      }
  }
  //insert at position
  void insertAtpos(struct node** head,int  val,int pos){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=val;
    if(pos==1){
      newnode->next=*head;
      *head=newnode;
      return;
    }
    //insertion at any pos
    struct node* temp=*head;
    int count=1;
    while(temp->next!=NULL && count<pos){
      temp=temp->next;
    }
  }
int main(){
  struct node* head=NULL;
}