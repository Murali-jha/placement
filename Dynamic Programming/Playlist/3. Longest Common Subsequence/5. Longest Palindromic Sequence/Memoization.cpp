class Solution {
public:
    
    
    int solve(string &a,string &b,vector<vector<int>> &t,int n,int n1){
        if(n==0 || n1==0){
            return 0;
        }
        if(t[n][n1]!=-1)
            return t[n][n1];
        
        if(a[n-1]==b[n1-1])
            return t[n][n1] = 1 + solve(a,b,t,n-1,n1-1);
        else
            return t[n][n1] = max(solve(a,b,t,n-1,n1),solve(a,b,t,n,n1-1));
    }
    
    
    int longestPalindromeSubseq(string s) {
        string temp = s;
        reverse(s.begin(),s.end());
        int n = s.length();
        vector<vector<int>> t(n+1,vector<int>(n+1,-1));
        
        return solve(s,temp,t,n,n);
    }
};
