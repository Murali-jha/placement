class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n+1,vector<int>(amount+1,-1));
        
        
        
        for(int i=1;i<=amount;i++){
            t[0][i] = INT_MAX-1;
        }
        
        for(int i=0;i<=n;i++){
            t[i][0] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][amount]==INT_MAX-1?-1:t[n][amount];
    }
};
