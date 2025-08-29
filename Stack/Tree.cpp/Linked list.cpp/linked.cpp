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
    void insertAtNode(Node* &head,int data){
        Node* temp=new Node(data);
        temp->data=data;
        head=temp;
    }
    void print(Node* &head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" "<<endl;
            temp=temp->next;
        }
    }
int main(){
   Node* node1=new Node(10);
Node* head=node1;
  insertAtNode(head,12);
  print(head);
  insertAtNode(head,15);
  print(head);
  insertAtNode(head,19);
  print(head);
}