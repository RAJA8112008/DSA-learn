#include<iostream>
using namespace std;
class Node{
  int data;
  Node*left;
  Node* right;
  //Constructor
  Node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
  }
  Node* InsertinBST(Node* root,int data){
       if(root==NULL){
        root=new Node(data);
        return root;
       }
       if(root->data>data){
        root->left=InsertinBST(root->left,data);
       }else{
        root->right=InsertinBST(root->right,data);
       }
       return root;
  }
  void InOrder(Node*root){
    if(root==NULL)return ;
    //LNR
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
  }
  Node*buildTree(){
    Node* root=NULL;
    int data;
    cout<<"Enter the values"<<endl;
    cin>>data;
    while(data!=-1){
      root=InsertinBST(root,data);
      cin>>data;
    }
    return root;
  }
};
int main(){
   Node* root=buildTree();
  
}