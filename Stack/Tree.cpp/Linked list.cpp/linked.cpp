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
//deletion any node
void deleteNode(int position,Node* &head){
  
  if(position==1){
   Node* temp=head;
   head=head->point;
   head->point=NULL;
   delete(temp);
  }else{
    Node* prev=NULL;
    Node* curr=head;
    int cnt=1;
    while(cnt<position){
      prev=curr;
      curr=curr->point;
      cnt++;
    }
    
  }
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
 //insert at position
 void insertAtposition(Node* &head,Node* & tail,int position,int data){
    if(position==1){
       insertAthead(head,data);
       return;
    }
    Node* temp=head;
  int cnt=1;
  while(cnt<position-1){
    temp=temp->point;
    cnt++;
  }
  //insert at last
   if(temp->point==NULL){
    insertAttail(tail,data);
    return;
   }
  //create Node
  Node* node=new Node(data);
  node->point=temp->point;
  temp->point=node;
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
print(head);
insertAttail(tail,30);
print(head);
insertAttail(tail,40);
print(head);
insertAtposition(head,tail,3,50);
print(head);
}