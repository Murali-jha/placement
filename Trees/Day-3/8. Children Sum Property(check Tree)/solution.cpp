int isSumProperty(Node *root)
    {
        if(root==NULL){
            return 1;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            int count = 0;
            if(temp->left){
                count+=temp->left->data;
                q.push(temp->left);
            }
            
            if(temp->right){
                count+=temp->right->data;
                q.push(temp->right);
            }
            
            if(count!=temp->data && count!=0){
                return 0;
            }
        }
        return 1;
    }
