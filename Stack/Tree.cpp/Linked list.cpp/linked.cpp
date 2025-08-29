#include<iostream>
using namespace std;
 class Node{
        public:
        int data;
        Node* point;
    };
int main(){
   Node* node1=new Node();
   cout<<node1->data<<endl;
}