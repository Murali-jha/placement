bool isSafe(bool graph[101][101],int n,vector<int> &color,int node,int c){
    
    
    for(int i=0;i<n;i++){
        if(graph[node][i] && color[i]==c){
            return false;
        }
    }
    
    
    return true;
}

bool solve(bool graph[101][101], int m, int n, int node, vector<int> &color){
    
    
    if(node == n){
        return true;
    }
    
    
    for(int i=0;i<m;i++){
        if(isSafe(graph,n,color,node,i)){
            color[node] = i;
            if(solve(graph,m,n,node+1,color)){
                return true;
            }
            color[node] = -1;
        }
    }
    
    
    
    return false;
}


bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> color(n,-1);
    return solve(graph,m,n,0,color);
}
