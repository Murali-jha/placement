class Solution {
public:
    
    
    
    int solve(int amount, vector<int>& coins,int n,vector<vector<int>> &t){
        if(amount==0)
            return 1;
        
        if(n==0)
            return 0;
        
        if(t[n][amount]!=-1)
            return t[n][amount];
        
        if(coins[n-1]<=amount)
            return t[n][amount] = solve(amount-coins[n-1],coins,n,t) + solve(amount,coins,n-1,t);
        else
            return t[n][amount] = solve(amount,coins,n-1,t);
    }
    
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> t(n+1,vector<int>(amount+1,-1));
        return solve(amount,coins,n,t);
    }
};
