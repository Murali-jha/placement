class Solution {
public:
    
    bool check(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    
    
    void solve(string s,int n,int ind,vector<vector<string>> &ans,vector<string> temp){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++){
            if(check(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(s,n,i+1,ans,temp);
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,s.length(),0,ans,temp);
        return ans;
    }
};
