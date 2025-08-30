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
//insertion at head
 void insertAthead(Node* &head,int data){
    //creation of node
    Node* temp=new Node(data);
    temp->point=head;
    head=temp;
 }
 //print the node
 void print(Node* head){
    
   while(head!=NULL){
    cout<<head->data<<" ";
    head=head->point;
   }
 }
int main(){
 Node* node1=new Node(10);
 Node* head=node1;
}