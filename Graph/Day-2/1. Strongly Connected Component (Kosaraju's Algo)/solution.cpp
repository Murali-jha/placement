#include<bits/stdc++.h>
void dfs(vector<int> adj[],int node,vector<int> &vis,stack<int> &s){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(adj,it,vis,s);
        }
    }
    s.push(node);
}

void revdfs(vector<int> adj[],int node,vector<int> &vis,vector<int> &ans){
    vis[node]=1;
    ans.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            revdfs(adj,it,vis,ans);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n],trans[n];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        trans[it[1]].push_back(it[0]);
    }
    stack<int> s;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adj,i,vis,s);
        }
    }
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    vector<vector<int>> ans;
    while(!s.empty()){
        int node=  s.top();
        s.pop();
        vector<int> temp;
        if(!vis[node]){
            revdfs(trans,node,vis,temp);
        }
        ans.push_back(temp);
    }
    return ans;
}
