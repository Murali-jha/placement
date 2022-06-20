class Solution {
public:
    
    int solve(vector<int> &coins,vector<vector<int>> &t,int amount,int n){
        if(amount==0)
            return 0;
        if(n==0)
            return INT_MAX-1;
        
        if(t[n][amount]!=-1)
            return t[n][amount];
        
        if(coins[n-1]<=amount){
            return t[n][amount] = min((1 + solve(coins,t,amount-coins[n-1],n)),solve(coins,t,amount,n-1));
        }
        else
            return t[n][amount] = solve(coins,t,amount,n-1);
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n+1,vector<int>(amount+1,-1));
        int x = solve(coins,t,amount,n);
        return x==INT_MAX-1?-1:x;
    }
};
