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
    
    void solve(TreeNode* root,map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> &mp,int k,int level){
        if(!root)
            return;
        
        mp[k].push({level,root->val});
        solve(root->left,mp,k-1,level+1);
        solve(root->right,mp,k+1,level+1);
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> mp;
        solve(root,mp,0,0);
        
        
        for(auto it:mp){
            vector<int> v;
            while(!it.second.empty()){
                v.push_back(it.second.top().second);
                it.second.pop();
            }
            ans.push_back(v);
        }
        return ans;
    }
};
