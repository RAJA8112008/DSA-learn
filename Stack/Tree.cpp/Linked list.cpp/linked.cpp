#include<stdio.h>
#include<stdlib.h>
 struct Node{
    int data;
    struct Node* next;
 };


   void insertAtpos(struct Node* head,int val,int pos){
      //creation of node
      struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
       newNode->data=val;
       //insert at head
       if(pos==1){
        struct Node* temp=head;
         while(temp->next!=head){
            temp=temp->next;
         }
         //insertion at  pos 1
         temp->next=newNode;
         newNode->next=head;
         head=newNode;
         return;
       }
   }
  //creation of LL 
struct Node* creatCLL(int n){
     if(n<=0) return NULL;
     //creation of Nodes
     struct Node* nodes[n];
     for(int i=0;i<n;i++){
      nodes[i]=(struct Node*)malloc(sizeof(struct Node));
      printf("Enter the data for %d :",i+1);
      scanf("%d",&nodes[i]);
     }
     //circular
     for(int i=0;i<n;i++){
        nodes[i]->next=nodes[(i+1)%n];
     }
     return nodes[0];
  }

  void display(struct Node* head){
     if(head==NULL){
       printf("Not NODES available");
     }
      struct Node* temp=head;
     do{
        printf("%d->",temp->data);
         temp=temp->next;
     }while(temp!=head);
  }
int main(){
    //number of nodes
    int n;
    printf("No. of nodes");
    scanf("%d",&n);
    struct Node* head=creatCLL(n);
      display(head);
};