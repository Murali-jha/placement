class Solution {
public:
    void sum(vector<int> v,int target, vector<vector<int>> &ans,int ind,int n,vector<int> &temp){
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=ind;i<n;i++){
            if(i!=ind && v[i]==v[i-1])
                continue;
            
            if(v[i]>target)
                break;
            
            temp.push_back(v[i]);
            sum(v,target-v[i],ans,i,n,temp);
            temp.pop_back();
            
        }
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        sum(candidates,target,ans,0,candidates.size(),temp);
        return ans;
    }
};
