#include<iostream>
using namespace std;

 class Node{
    public:
      int data;
      Node* left;
      Node* right;
    Node(int data){
     this->data=data;
     this->left=NULL;
     this->right=NULL;
    }
 };
Node* InsertBST(Node* root,int data){
     if(root==NULL){
        root=new Node(data);
        return root;
     }
     if(root->data>data){
       root->left= InsertBST(root->left,data);
     }else{
        root->right=InsertBST(root->right,data);
     }
     return root;
 }
 Node* Insert(Node*root){
    int data;
    cin >> data;
    while(data!=-1){
        root=InsertBST(root,data);
        cin>>data;
    }
   return root;
 }
  void InOrderTraversal(Node*root){
      if(root==NULL)return;
      //LNR
      InOrderTraversal(root->left);
      cout<<root->data<<" "<<endl;
      InOrderTraversal(root->right);
  }
int main(){  
   Node* root=NULL;
  cout<<"Enter the values in root/nodes:"<<endl;
  root=Insert(root);
cout<<"INorder traversal";
InOrderTraversal(root);
 cout<<endl;
}