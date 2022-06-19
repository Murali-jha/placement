class Solution {
public:
    
    
    int solve(int k,int n,vector<vector<int>> &t){
        if(n==0 || n==1){
            return n;
        }
        
        if(k==1){
            return n;
        }
        if(t[k][n]!=-1)
            return t[k][n];
        
        
        int mn = INT_MAX;
        for(int i=1;i<=n;i++){
            int temp  = 1 + max(solve(k-1,i-1,t), solve(k,n-i,t));
            mn = min(mn,temp);
        }
        return t[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> t(k+1,vector<int>(n+1,-1));
        return solve(k,n,t);
    }
};
