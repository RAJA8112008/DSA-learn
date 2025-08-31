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
    while(head!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//inser at tail;
void insertAtnode(Node* &tail,int data){
    Node* temp=new Node(data);
    
}
int main(){
  Node* node1=new Node(5);
   Node* head=node1;
   Node* tail=node1;
     insertAthead(head,12);
     insertAthead(head,14);
      insertAthead(head,16);
      print(head);
}