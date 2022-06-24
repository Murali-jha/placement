/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    class BSTIterator{
      public:
        bool check = true;
        stack<TreeNode*> s;
        BSTIterator(TreeNode* root,bool value){
            check = value;
            pushall(root);
        }
        
        int next() {
            TreeNode* temp = s.top();
            s.pop();
            check?pushall(temp->right):pushall(temp->left);
            return temp->val;
        }

        void pushall(TreeNode* root){
            while(root){
                s.push(root);
                root = check?root->left:root->right;
            }
        }
    };
    
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        
        auto l = BSTIterator(root,true);
        auto r = BSTIterator(root,false);
        int left = l.next();
        int right = r.next();
        while(left<right){
            if(left+right==k)
                return true;
            else if(left+right<k){
                left = l.next();
            }
            else{
                right = r.next();
            }
        }
        return false;
    }
};
