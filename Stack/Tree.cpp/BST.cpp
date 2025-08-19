#include<iostream>
using namespace std;
//creation of BST using class
class Node{
  public:
  int data;
  Node* right;
  Node* left;
  //constructor
  Node(int data){
    this->data=data;
    this->right=NULL;
    this->left=NULL;
  }
};

//Insertion in BST
Node* InsertinBST(Node* root,int data){
    //check root is available or not
    if(root==NULL){
       root = new Node(data);
      return root;
    }else if(root->data>data){
      root->left=InsertinBST(root,data);
    }else{
      root->right=InsertinBST(root,data);
    }
    return root;
}
//delection in BST
 Node* deletioninBST(Node* root,int data){
     if(root==NULL){
      return NULL;
     }
     if(root->data==target){
       //case 1: left  !right
       if(root->left==NULL && root->right==NULL){
          delete root;
          return root;
       }else if(root->left!=NULL && root->right==NULL){
        
       }
     }
 }

int main(){
 int target;
}