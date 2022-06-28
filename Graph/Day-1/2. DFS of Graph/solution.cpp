void dfs(vector<int> adj[],vector<int> &vis,vector<int> &ans,int node){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,vis,ans,it);
            }
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans,vis(V,0);
        dfs(adj,vis,ans,0);
        return ans;
    }
