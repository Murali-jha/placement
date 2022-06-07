class Solution {
public:
    
    void sum(vector<int> v,int target, vector<vector<int>> &ans,int i,int n,vector<int> &temp){
        if(i==n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(v[i]<=target){
            temp.push_back(v[i]);
            sum(v,target-v[i],ans,i,n,temp);
            temp.pop_back();
        }
        sum(v,target,ans,i+1,n,temp); 
        
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sum(candidates,target,ans,0,candidates.size(),temp);
        return ans;
    }
};
