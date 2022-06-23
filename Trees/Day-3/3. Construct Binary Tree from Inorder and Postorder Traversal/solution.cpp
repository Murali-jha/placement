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
    
    TreeNode* solve(vector<int>& inorder, int instart,int inend,vector<int>& postorder,int poststart,int postend,map<int,int> &mp){
        if(poststart>postend || instart>inend){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mp[root->val];
        int numsLeft = inroot-instart;
        
        root->left = solve(inorder,instart,inroot-1,postorder,poststart,poststart+numsLeft-1,mp);
        
        root->right = solve(inorder,inroot+1,inend,postorder,poststart+numsLeft,postend-1,mp);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};
