#include<iostream>
#include<queue>
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
      node* root= new node(d);
   cout<<"Enter the value of Left:"<<d<<endl;
   root->left=buildTree();
   cout<<"Enter the value of Right:"<<d<<endl;
   root->right=buildTree();
   return root;
}
 void levelOrderTravelsel(node*root){
   queue<node*>q;
   q.push(root);
   //empty prcess
   while(!q.empty()){
   node* temp=q.front();
    q.pop();
    cout<<temp->data<<" ";
    q.pop();
    if(temp->left){
      q.push(temp->left);
   }
   if(temp->left){
      q.push(temp->left);
   }
   }
 }

int main(){
  node* root=NULL;
  root=buildTree();
  cout<<"Printing the tree"<<endl;
  levelOrderTravelsel(root);
  return 0;
}