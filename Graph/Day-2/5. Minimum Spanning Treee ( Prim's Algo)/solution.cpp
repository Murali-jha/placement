int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(V,INT_MAX);
        vector<bool> mst(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        key[0]=0;
        while(!pq.empty()){
            int node= pq.top().second;
            pq.pop();
            mst[node] = true;
            for(auto it:adj[node]){
                if(mst[it[0]]==false && key[it[0]]>it[1]){
                    key[it[0]] = it[1];
                    pq.push({it[1],it[0]});
                }
            }
        }
        
        
        int ans=0;
        for(auto it:key){
            ans+=it;
        }
        return ans;
    }
