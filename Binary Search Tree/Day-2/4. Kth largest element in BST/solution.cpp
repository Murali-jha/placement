void inorder(Node* root,int k,int &count,int &ans){
        if(root== NULL)
            return;
        
        inorder(root->right,k,count,ans);
        count++;
        if(count==k)
            ans = root->data;
        inorder(root->left,k,count,ans);
    }
    
    
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int count=  0;
        int ans = -1;
        inorder(root,k,count,ans);
        return ans;
    }
