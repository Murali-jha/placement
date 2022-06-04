class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3){
            return ans;
        }
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int target = 0 - nums[i];
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[left] + nums[right];
                if(sum<target){
                    left++;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    while(left<right && nums[left]==v[1]){
                        left++;
                    }
                    while(left<right && nums[right]==v[2]){
                        right--;
                    }
                    ans.push_back(v);
                }
            }
            
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
        }
        
        return ans;
    }
};
