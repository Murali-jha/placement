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
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(1){
            if(node){
                s.push(node);
                node = node->left;
            }
            else{
                if(s.empty())
                    break;
                TreeNode* temp = s.top();
                ans.push_back(temp->val);
                s.pop();
                node = temp->right;
            }
        }
        
        
        return ans;
    }
};
