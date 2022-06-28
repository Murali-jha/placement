class Solution {
public:
    
    
    bool solve(vector<int> adj[],vector<int> &vis,vector<int> &dfsvis,int node){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(!solve(adj,vis,dfsvis,it)){
                    return false;
                }
            }
            else if(dfsvis[it]){
                return false;
            }
        }
        dfsvis[node]=0;
        return true;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0),dfsvis(numCourses,0);
        vector<int> adj[numCourses];
        
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(!solve(adj,vis,dfsvis,i)){
                    return false;
                }
            }
        }
        
        return true;
    }
};
