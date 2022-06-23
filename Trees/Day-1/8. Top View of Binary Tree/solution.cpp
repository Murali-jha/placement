vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int,int> mp;
        if(!root){
            return ans;
        }
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* temp = q.front().first;
                int order = q.front().second;
                q.pop();
                if(mp.find(order)==mp.end()){
                    mp[order] = temp->data;
                }
                if(temp->left){
                    q.push({temp->left,order-1});
                }
                
                if(temp->right){
                    q.push({temp->right,order+1});
                }
            }
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
