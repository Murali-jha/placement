vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dis(V,100000000);
        dis[S] = 0;
        for(int i=1;i<=V-1;i++){
            for(auto it:adj){
                if(dis[it[0]]+it[2]<dis[it[1]]){
                    dis[it[1]] = dis[it[0]]+it[2];
                }
            }
        }
        
        return dis;
    }
