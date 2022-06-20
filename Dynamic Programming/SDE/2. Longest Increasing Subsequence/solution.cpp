class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(nums[j]>nums[i] && lis[j]<=lis[i]){
                    lis[j] = lis[i]+1;
                }
            }
        }
        
        
        
        int ans=  INT_MIN;
        for(auto it:lis){
            ans = max(it,ans);
        }
        return ans;
    }
};
