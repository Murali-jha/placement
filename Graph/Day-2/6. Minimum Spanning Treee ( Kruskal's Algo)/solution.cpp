struct Node{
    int weight,u,v;
    Node(int wt,int x,int y){
        weight = wt;
        u = x;
        v = y;
    }
};



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	
	bool static comp(Node a,Node b){
	    return a.weight<b.weight;
	}
	
	
	int findParent(int node,vector<int> parent){
	    if(parent[node] == node){
	        return node;
	    }
	    
	    return parent[node] = findParent(parent[node],parent);
	}
	
	
	void union1(int u,int v,vector<int> &parent,vector<int> &rank){
	    u = findParent(u,parent);
	    v = findParent(v,parent);
	    
	    if(rank[u]>rank[v]){
	        parent[v] = u;
	    }
	    else if(rank[u]<rank[v]){
	        parent[u] = v;
	    }
	    else{
	        parent[v]=u;
	        rank[u]++;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<Node> v;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                v.push_back(Node(it[1],i,it[0]));
            }
        }
        
        vector<int> parent(V),rank(V);
        for(int i=0;i<V;i++){
            parent[i] = i;
            rank[i] = 0;
        }
        sort(v.begin(),v.end(),comp);
        int cost = 0;
        
        for(auto it:v){
            if(findParent(it.u,parent)!=findParent(it.v,parent)){
                cost +=  it.weight;
                union1(it.u,it.v,parent,rank);
            }
        }
        
        return cost;
    }
};
