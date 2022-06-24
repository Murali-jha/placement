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
    
    TreeNode* find(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
    
    TreeNode* helper(TreeNode* root){
        if(root->right==NULL)
            return root->left;
        
        if(root->left==NULL)
            return root->right;
        
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = find(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return helper(root);
        }
        
        TreeNode* curr = root;
        while(curr){
            if(curr->val>key){
                if(curr->left && curr->left->val==key){
                    curr->left = helper(curr->left);
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->right && curr->right->val==key){
                    curr->right = helper(curr->right);
                }
                else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};
