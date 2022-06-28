class Solution {
public:
    
    
    bool solve(vector<vector<int>>& graph,vector<int> &col,int node,int c){
        col[node] = c;
        for(auto it:graph[node]){
            if(col[it]==-1){
                if(!solve(graph,col,it,1-c))
                    return false;
                
            }
            else if(col[it]==c)
                return false;
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!solve(graph,col,i,0)){
                    return false;
                }
            }
        }
        
        return true;
    }
};
