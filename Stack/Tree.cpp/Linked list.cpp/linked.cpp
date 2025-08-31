#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int data){
    this->data=data;
    this->next=NULL;
}
};
//deletion 
void deleteNode(Node* &head,int position){
 
}
//insert at tail
void insertAttail(Node* &tail,int data){
 Node* temp=new Node(data);
 tail->next=temp;
 tail=temp;
}
void insertAthead(Node* &head,int data){
  Node* temp=new Node(data);
  temp->next=head;
  head=temp;
}
void print(Node*head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtposition(Node* &head,Node* &tail,int position,int data){
    if(position==1){
        insertAthead(head,data);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    Node* newNode=new Node(data);
     newNode->next=temp->next;
     temp->next=newNode;
     //at tail
     if(temp==NULL){
        insertAttail(tail,data);
     }
}
int main(){
Node* node1=new Node(5);
Node* head=node1;
Node* tail=node1;
// insertAthead(head,20);
// print(head);
// insertAthead(head,55);
// print(head);
// insertAthead(head,65);
// print(head);
insertAttail(tail,15);
print(head);
insertAttail(tail,25);
print(head);
insertAttail(tail,35);
print(head);
insertAtposition(head,tail,1,51);
print(head);
}