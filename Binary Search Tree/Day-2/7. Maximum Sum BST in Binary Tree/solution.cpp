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


class NodeValue{
  public:
    int minNode,maxNode,size,sum;
    NodeValue(int x,int y,int z,int s){
        minNode = x;
        maxNode = y;
        size = z;
        sum = s;
    }
};



class Solution {
    
    int maxSum=INT_MIN;
    
    NodeValue solve(TreeNode* root){
        if(!root){
            return NodeValue(INT_MAX,INT_MIN,0,0);
        }
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        if(left.maxNode<root->val && root->val<right.minNode){
            
            maxSum = max(max(0,maxSum),root->val+left.sum+right.sum);
            return NodeValue(min(root->val,left.minNode),max(root->val,right.maxNode),left.size + right.size + 1,root->val+left.sum+right.sum);
        }
        
        return NodeValue(INT_MIN,INT_MAX,max(left.size,right.size),0);
    }
    
    
    
    
    
public:
    int maxSumBST(TreeNode* root) {
        //cout<< solve(root).size;
        return maxSum;
    }
};
