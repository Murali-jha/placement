class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp = target-nums[i]-nums[j];
                int left = j+1;
                int right = n-1;
                while(left<right){
                    int sum = nums[left] + nums[right];
                    
                    if(sum<temp){
                        left++;
                    }
                    else if(sum>temp){
                        right--;
                    }
                    else{
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        ans.push_back(v);
                        while(left<right && nums[left]==v[2]){
                            left++;
                        }
                        while(left<right && nums[right]==v[3]){
                            right--;
                        }
                    }
                }
                
                while(j+1<n && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]){
                    i++;
            }
        }
        
        return ans;
    }
};
