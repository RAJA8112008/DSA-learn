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
 }
 struct Node* reverseLL(struct Node* head){
    struct Node* curr=head;
    struct Node* next=NULL;
    struct Node* prev=NULL;
    while(curr!=NULL){
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
      // next = curr->next;    // save next
       // curr->next = prev;    // reverse link
        //prev = curr;          // move prev ahead
        //curr = next;  
    }
    return prev;
 }
int main(){
   struct Node* head=createNode(10);
   head->next=createNode(20);
   head->next->next=createNode(30);
   head->next->next->next=createNode(40);
   head->next->next->next->next=createNode(50);
   print(head);
   head=reverseLL(head);
   print(head);

}