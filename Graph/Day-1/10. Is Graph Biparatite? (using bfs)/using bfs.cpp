class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                queue<int> q;
                q.push(i);
                col[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it:graph[node]){
                        if(col[it]==-1){
                            col[it] = 1 - col[node];
                            q.push(it);
                        }
                        else if(col[it]==col[node]){
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
