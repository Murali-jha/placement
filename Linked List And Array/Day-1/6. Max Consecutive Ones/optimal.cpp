class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans =  INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else{
                count=0;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};
