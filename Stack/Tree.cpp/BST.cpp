#include<iostream>
using namespace std;
class Node{
    public:
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
    Node* InsertData(Node* root,int data){
      if(root==NULL){
        root=new Node(data);
        return root;
      }
      if(root->data>data){
        root->left=InsertData(root->left,data);
      }else{
        root->right=InsertData(root->right,data);
      }
     return root;
    }
 Node* takeData(Node* root){
    int data;
    cin>>data;
      while(data!=-1){
        root=InsertData(root,data);
        cin>>data;
      }
      return root;
    }
    void InOrderTravrse(Node* root){

        //LNR
        if(root==NULL)return;
        InOrderTravrse(root->left);
        cout<<root->data<<" "<<endl;
        InOrderTravrse(root->right);
    }
    bool Search(Node* root,int target){
        
    }
int main(){    
  Node* root=NULL;
  cout<<"Enter the data:"<<endl;
  root= takeData(root);
  cout<<"InO rder";
  InOrderTravrse(root);
  cout<<endl;
}