/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 bool solvex(TreeNode* root,int B,vector<int> &ans){
     if(!root){
         return false;;
     }
     
     ans.push_back(root->val);
     
     if(root->val==B){
         return true;
     }
     
     if(solvex(root->left,B,ans) || solvex(root->right,B,ans)){
         return true;
     }
     ans.pop_back();
     return false;
 }
 
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    solvex(A,B,ans);
    return ans;
}
