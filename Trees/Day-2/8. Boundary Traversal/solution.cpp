/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>

void solve(TreeNode<int>* root, vector<int> &ans){
    if(!root)
        return;
    
    solve(root->left,ans);
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    solve(root->right,ans);
}



vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!root)
        return ans;
    
    ans.push_back(root->data);
    TreeNode<int>* temp  =root->left;
    
    //left
    while(temp){
        if(temp->left || temp->right)
            ans.push_back(temp->data);
        if(temp->left){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    
    if(root->left || root->right){
        solve(root,ans);
    }
    
    //right
    temp  = root->right;
    stack<int> s;
    while(temp){
        if(temp->left || temp->right)
            s.push(temp->data);
        if(temp->right){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
