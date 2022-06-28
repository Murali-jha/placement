vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dis(V,INT_MAX);
        queue<int> q;
        q.push(S);
        dis[S]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dis[node]+it[1]<dis[it[0]]){
                    dis[it[0]] = dis[node] + it[1];
                    q.push(it[0]);
                }
            }
        }
        return dis;
    }
