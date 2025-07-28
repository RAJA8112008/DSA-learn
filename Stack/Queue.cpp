
void traversRight(TreeNode<int> *root,vector<int>&ans){
    // base case
    if((root==NULL)||(root->right==NULL && root->left==NULL))return;
    if(root->right){
       ans.push_back(root->data);
    }else{
        ans.push_back(root->data);
    }
    ans.push_back(root->data);
}
  void traverseLeaf(TreeNode<int>*root,vector<int>&ans){
      //base case
      if(root==NULL)return;
      if(root->right ==NULL &&root->left==NULL){
          ans.push_back(root->data);
          return;
      }
  }
 void traverseLeft(TreeNode<int> *root,vector<int>&ans){
    if((root==NULL)||(root->left==NULL && root->right==NULL))return;
      if(root->left){
          ans.push_back(root->data);
      }else{
          ans.push_back(root->data);
      }
      traverseLeft(root,ans);
     
 }

vector<int> traverseBoundary(TreeNode<int> *root)
{
  vector<int>ans;
    if(root==NULL)return ans;
    ans.push_back(root);
    traversRight(root->right,ans);
    traversRight(root->left,ans);
    traverseLeaf(root,ans);
     traverseLeft(root->left,ans);
      traverseLeft(root->right,ans);
      return ans;
}
