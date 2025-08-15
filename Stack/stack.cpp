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
   q.push(NULL);
   //empty process
   while(!q.empty()){
   node* temp=q.front();
    q.pop();
    if(temp==NULL){
      cout<<endl;
      if(!q.empty()){
         q.push(NULL);
      }
    }else{
    cout<<temp->data<<" ";

    if(temp->left){
      q.push(temp->left);
   }
   if(temp->right){
      q.push(temp->left);
   }
   }
 }
 }
//  void inorder(node*root){
//    //base case
//       if(root==NULL){
//          return;
//       }
//       inorder(root->left);
//       cout<<root->data<<" ";
//       inorder(root->right);
//   }
void postorder(node*root){
   //base case
   if(root==NULL){
      return;
   }
   //NLR
   postorder(root->left);
   postorder(root->right);
   cout<<root->data<<" ";
}
int main(){
  node* root=NULL;
  
  root=buildTree();
  cout<<"Printing the tree"<<endl;
  levelOrderTravelsel(root);
  cout<<"Postorder Arrangement :"<<endl;
  postorder(root);
  return 0;
}