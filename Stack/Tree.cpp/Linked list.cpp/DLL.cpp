#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    //constructor
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
//insert at head
void insertAtHead(Node*&head,int data){
   Node* temp=new Node(data);
   temp->next=head;
   
   head->prev = temp;
   head=temp;
}
//insert at end
void insertAtTail(Node* &tail,int data){
 Node* temp=new Node(15);
  
}
void print(Node*&head){
    Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
int main(){
 Node* node1=new Node(10);
 Node* head=node1;
 Node* tail=node1;
 insertAtHead(head,15);
  insertAtHead(head,20);
  insertAtHead(head,20);
 print(head);
}