class Solution {
public:
    
    
    
    int solve(vector<int> &cuts, int i,int j,vector<vector<int>> &t){
        if(i>j){
            return 0;
        }    
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        int ans = INT_MAX;
        for(int k=i;k<=j;k++){
            int temp = solve(cuts,i,k-1,t) + solve(cuts,k+1,j,t) + (cuts[j+1]-cuts[i-1]);
            
            ans = min(ans,temp);
        }
        
        return t[i][j] = ans;
    }
    
    
    
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> t(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(cuts,1,cuts.size()-2,t);
    }
};
