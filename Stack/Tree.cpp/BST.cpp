#include<iostream>
using namespace std;
class Node{
    int data;
    Node* left;
    Node* right;
//constructor
    Node(int data){
      this->data=data;
      this->left=NULL;
      this->right=NULL;
    }
};
int main(){    
  Node* root=NULL;
}