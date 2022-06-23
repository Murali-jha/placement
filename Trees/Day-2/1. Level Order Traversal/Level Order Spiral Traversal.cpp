vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    bool check = false;
    while(!q.empty()){
        int size = q.size();
        vector<int> v(size);
        for(int i=0;i<size;i++){
            Node* temp  =q.front();
            q.pop();
            int ind = check? i: size-i-1;
            v[ind] = temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        check = !check;
        for(int i=0;i<size;i++){
            ans.push_back(v[i]);
        }
    }
    return ans;
}
