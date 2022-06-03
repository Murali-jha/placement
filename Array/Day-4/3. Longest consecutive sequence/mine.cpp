class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int small = INT_MAX;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            small = min(small,nums[i]);
        }
        int ans = 0;
        int count = 1;
        int prev = small;
        for(auto it: s){
            
            if(it == prev+1){
                count++;
                prev = it;
            }
            else{
                prev = it;
                count= 1 ;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};
