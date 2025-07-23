#include<iostream>
using namespace std;
  
class node{
   public:
   int data;
   node* left;
   node* right;
   //constructor
   node(int d){
      this->data=d;
      this->left=NULL;
      this->right=NULL;
   }
};
node* buildTree(){
       
   int d;
   cin>>d;
   if(d==-1){
      return NULL;
   }
  node* root=new node(d);
   
  cout<<"Enter the Left node data:"<<d<<endl;
  root->left=buildTree();
cout<<"Enter the Right node data:"<<d<<endl;
  root->right=buildTree();
 return root;
   }
int main(){
   node* root=NULL;
   root=buildTree();
};