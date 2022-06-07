class Solution {
public:
    
    void sum(vector<int> v,int target, set<vector<int>> &ans,int i,int n,vector<int> &temp){
        if(target==0){
            ans.insert(temp);
        }
        
        if(i>=n || target<0){
            return;
        }
        
        
        sum(v,target,ans,i+1,n,temp);
        temp.push_back(v[i]);
        sum(v,target-v[i],ans,i,n,temp);
        temp.pop_back();
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> ans1;
        sum(candidates,target,ans1,0,candidates.size(),temp);
        for(auto it:ans1){
            ans.push_back(it);
        }
        return ans;
    }
};
