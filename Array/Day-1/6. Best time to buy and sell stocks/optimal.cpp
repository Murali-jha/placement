class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int small = INT_MAX;
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            small = min(small,prices[i]);
            ans = max(ans,prices[i]-small);
        }
        return ans;
    }
};
