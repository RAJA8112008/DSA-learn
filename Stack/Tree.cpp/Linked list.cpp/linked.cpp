#include<stdio.h>
#include<stdlib.h>
struct Node{
   int data;
   struct Node* next;
};
struct Node* createNode(int data){
     struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
     newnode->data=data;
     newnode->next=NULL;
     return newnode;
 }
 void print(struct Node* head){
      struct Node* temp=head;
      while(temp!=NULL){
         printf("%d ",temp->data);
         temp=temp->next;
      }
      printf("\n");
 }
int main(){
   struct Node* head=createNode(10);
   head->next=createNode(20);
   head->next->next=createNode(30);
   head->next->next->next=createNode(40);
   head->next->next->next->next=createNode(50);
   print(head);
}