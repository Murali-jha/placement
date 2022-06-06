class Solution {
public:
    
    void subset(vector<int> nums,set<vector<int>> &s,int i,vector<int> temp){
        if(i==nums.size()){
            //sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        
        subset(nums,s,i+1,temp);
        temp.push_back(nums[i]);
        subset(nums,s,i+1,temp);
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        subset(nums,s,0,temp);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};
