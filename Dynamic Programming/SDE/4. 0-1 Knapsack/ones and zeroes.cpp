class Solution {
public:
    
    pair<int,int> countZeroes(string s){
        int count0 = 0,count1=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')
                count0++;
            else{
                count1++;
            }
        }
        return {count0,count1};
    }
    
    int solve(vector<string>& strs, int m, int n, int i,vector<vector<vector<int>>> &t){
        if(i==0 || (m==0 && n==0)){
            return 0;
        }
        
        if(t[m][n][i]!=-1)
            return t[m][n][i];
        
        pair<int,int> p = countZeroes(strs[i-1]);
        if(p.first<=m && p.second<=n){
            return t[m][n][i] = max(1+solve(strs,m-p.first,n-p.second,i-1,t),solve(strs,m,n,i-1,t));
        }
        else{
            return t[m][n][i] = solve(strs,m,n,i-1,t);
        }
    }
        

    int findMaxForm(vector<string>& strs, int m, int n) {
        int i  =strs.size();
        vector<vector<vector<int>>> t(m+1,vector<vector<int>>(n+1,vector<int>(i+1,-1)));
        return solve(strs,m,n,strs.size(),t);
    }
};
