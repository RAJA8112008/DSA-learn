#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* point;
    Node(int data){
     this->data=data;
     this->point=NULL;
    }
};
//insert at tail
void insertAttail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->point=temp;
    tail=temp;
}
//insertion at head
 void insertAthead(Node* &head,int data){
    //creation of node
    Node* temp=new Node(data);
    temp->point=head;
    head=temp;
 }
 //print tail 
 void printTail(Node* tail){
  while(tail!=NULL){
    cout<<tail->data<<" ";
    tail=tail->point;
  }
   cout<<endl;
 }
 //print the node
 void print(Node* head){
    
   while(head!=NULL){
    cout<<head->data<<" ";
    head=head->point;
   }
   cout<<endl;
 }
int main(){
 Node* node1=new Node(10);
 Node* head=node1;
 Node* tail=node1;
//  insertAthead(head,20);
//  print(head);
//  insertAthead(head,30);
//   print(head);
//  insertAthead(head,40);
//    print(head);
insertAttail(tail,20);
printTail(tail);
insertAttail(tail,30);
printTail(tail);
insertAttail(tail,40);
printTail(tail);
}