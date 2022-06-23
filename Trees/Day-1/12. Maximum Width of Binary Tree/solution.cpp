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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;
            int first = 0;
            int last = 0;
            for(int i=0;i<size;i++){
                long long int id = q.front().second - mmin;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i==0){
                    first = id;
                }
                if(i==size-1){
                    last = id;
                }
                
                if(temp->left){
                    q.push({temp->left,2*id+1});
                }
                
                if(temp->right){
                    q.push({temp->right,2*id+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};
