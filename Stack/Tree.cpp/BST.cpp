#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node*left;
  Node* right;
  //Constructor
  Node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
  }
};
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
  Node* buildTree(){
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
  Node* findmin(Node*root){
    if(root==NULL)return NULL;
    while(root->left!=NULL){
      root=root->left;
    }
    return root;
  }
  Node* deletinBST(Node*root,int target){
    if(root==NULL)return NULL;
    if(root->data==target){
       if(root->left==NULL && root->right==NULL){
         delete root;
         return NULL;
       }else if(root->left==NULL && root->right!=NULL){
         Node* temp=root->right;
         delete root;
         return temp;
       }else if(root->right==NULL && root->left!=NULL){
         Node* temp=root->left;
         delete root;
         return temp;
       }
       else
       {
           Node*Succesor=findmin(root->right);
           root->data=Succesor->data;
           root->right=deletinBST(root->right,Succesor->data);
       }
       return root;
    }
    else if(root->data>target){
      root->left = deletinBST(root->left,target);
    }else{
  root->right=deletinBST(root->right,target);
    }
   }
int main(){
   Node* root=buildTree();
  cout<<"Inorder data"<<" ";
  InOrder(root);
  cout<<endl;
  int target;
  cout<<"Enter the target "<<endl;
  cin>>target;
  root=deletinBST(root,target);
  cout<<"Inorder after deleetion";
  InOrder(root);
  cout<<endl;
}
