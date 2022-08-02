Node* deleteNode(Node* root, int k)
    {
        //Your code here
        if(root==NULL){
            return NULL;
        }
        if(root->data>=k){
            root->left = deleteNode(root->left,k);
            return root->left;
        }
        root->right = deleteNode(root->right,k);
        return root;
    }
