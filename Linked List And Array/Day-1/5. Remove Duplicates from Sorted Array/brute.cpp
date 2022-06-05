class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k =  0;
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            if(mp[nums[i]]==0){
                mp[nums[i]]=1;
                nums[k++] = nums[i];
            }
            
        }
        return k;
    }
};
