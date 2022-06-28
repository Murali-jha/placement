void solve(stack<int> &s,vector<int> &vis,vector<int> adj[],int node){
	    vis[node] = 1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            solve(s,vis,adj,it);
	        }
	    }
	    s.push(node);
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> topo,vis(V,0);
	    stack<int> s;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            solve(s,vis,adj,i);
	        }
	    }
	    
	    while(!s.empty()){
	        topo.push_back(s.top());
	        s.pop();
	    }
	    return topo;
	}
