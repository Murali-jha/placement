class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        
        for(auto num: nums){
            if(!s.count(num-1)){
                int curr = num;
                int currentStreak = 1;
                while(s.count(curr+1)){
                    currentStreak++;
                    curr = curr+1;
                }
                
                ans = max(ans,currentStreak);
            }
        }
        return ans;
    }
};
