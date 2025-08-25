#include<iostream>
using namespace std;

// Creation of BST using class
class Node{
public:
    int data;
    Node* right;
    Node* left;
    // constructor
    Node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

// Insertion in BST
Node* InsertinBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data < root->data){
        root->left = InsertinBST(root->left, data);
    } else {
        root->right = InsertinBST(root->right, data);
    }
    return root;
}

// InOrder traversal
void InOrder(Node* root){
    if(root == NULL) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

// Find min value node in BST
Node* findmin(Node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

// Deletion in BST
Node* deletioninBST(Node* root, int target){
    if(root == NULL) return NULL;

    if(target < root->data){
        root->left = deletioninBST(root->left, target);
    } 
    else if(target > root->data){
        root->right = deletioninBST(root->right, target);
    } 
    else {
        // Node found
        // Case 1: No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // Case 2: One child (right only)
        else if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 3: One child (left only)
        else if(root->right == NULL){
            
            Node* temp = root->left;
            delete root;
            return temp;    
        }
        // Case 4: Two children
        else{
            Node* succesor = findmin(root->right);
            root->data = succesor->data;
            root->right = deletioninBST(root->right, succesor->data);
        }
    }
    return root;
}

// Build tree from user input
Node* buildTree(){
    Node* root = NULL;
    int data;
    cout << "Enter values to insert in BST (-1 to stop):" << endl;
    cin >> data;
    while(data != -1){
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
