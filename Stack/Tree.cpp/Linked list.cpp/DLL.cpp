#include<iostream>
using namespace std;
class Node{
    public:
int data;
Node* next;
Node*prev;
//constructor
Node(int data){
this->data=data;
this->prev=NULL;
this->next=NULL;
}

};
//delection in node
void deleteNode(Node* &head,int position){
  if(position==1){
       Node* temp=head;
       head=temp->next;
       temp->next=NULL;
       delete temp;
       return;
  }
  Node* curr=head;
  Node* prev=NULL;
  int cnt=1;
  
  while(cnt<position){
    prev=curr;
    curr=curr->next;
    cnt++;
  }
  //deletion process
  prev->next=curr->next;
  curr->next=NULL;
  curr->prev=NULL;
  delete curr;

}
//insert at head
void insertAthead(Node* &head,int data){
   Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
//print the list
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//inser at tail;
void insertAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
   temp->prev=tail;
   tail->next=temp;
   tail=temp;
}
//insert at position 
void insertAtposition(Node* &head,Node* &tail,int position,int data){
    if(position==1){
        insertAthead(head,data);
        return;
    }
   //traverse
   Node* temp=head;
   int cnt=1;
   while(cnt<position-1){
    temp=temp->next;
    cnt++;
   }

   
   //insert at last
   if(temp->next==NULL){
    insertAtTail(tail,data);
    return;
   }
   Node* newtemp=new Node(data);
   newtemp->next=temp->next;
   temp->next->prev=newtemp;
   temp->next=newtemp;
   newtemp->prev=temp;
}
int main(){
  Node* node1=new Node(5);
   Node* head=node1;
   Node* tail=node1;
    //  insertAthead(head,12);
    //  insertAthead(head,14);
    //   insertAthead(head,16);
    //   print(head);
      insertAtTail(tail,45);
      insertAtTail(tail,89);

      print(head);
      insertAtposition(head,tail,3,99);
      print(head);
      deleteNode(head,3);
      print(head);
}