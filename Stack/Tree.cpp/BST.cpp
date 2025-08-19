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
     //find min
     Node* findmin(Node* root){
      if(root->left!=NULL)return NULL;
        while(root->left!=NULL){
          root=root->left;
        }
        return root;
     }
     void InOrder(Node* root) {
    if (root == NULL) return;
    // LNR
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

     if(root->data==target){
       //case 1: left  !right
       if(root->left==NULL && root->right==NULL){
          delete root;
          return root;
       }else if(root->left!=NULL && root->right==NULL){
         Node* temp=root->left;
         delete root;
         return temp;
       }else if(root->right!=NULL && root->left==NULL){
        Node* temp=root->right;
        delete root;
        return temp;
       }else{
        //both nodes are present
        Node* succesor=findmin(root->right);
           root->data =succesor->data;
           root->right=deletioninBST(root->right,succesor->data);
           return root;
       }
     }else if(root->data<target){
       root->right=deletioninBST(root->right,target);
     }else{
      root->left=deletioninBST(root->left,target);
     }
     return root;
 }
  Node* buildTree() {
    Node* root = NULL;
    int data;
    cout << "Enter values to insert in BST (-1 to stop):" << endl;
    cin >> data;
    while (data != -1) {
        root = InsertinBST(root, data);
        cin >> data;
    }
    return root;
}
int main(){
 Node* root = buildTree();

    cout << "Inorder traversal: ";
    InOrder(root);
    cout << endl;

    int target;
    cout << "Enter the target to delete: ";
    cin >> target;

    root = deletioninBST(root, target);

    cout << "Inorder after deletion: ";
    InOrder(root);
    cout << endl;

    return 0;
}