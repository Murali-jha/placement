class Solution {
public:
    
    void solve(vector<vector<int>> &ans,vector<int> &nums,vector<int> &vis,vector<int> &temp){
        if(temp.size()>=nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(vis[i]==0){
                temp.push_back(nums[i]);
                vis[i] = 1;
                solve(ans,nums,vis,temp);
                vis[i] = 0;
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vis(nums.size(),0);
        vector<int> temp;
        solve(ans,nums,vis,temp);
        return ans;
    }
};
