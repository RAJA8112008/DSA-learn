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
int main(){
Node* node1=new Node(15);
Node* head=node1;
insertAthead(head,20);
print(head);
insertAthead(head,55);
print(head);
insertAthead(head,65);
print(head);
}