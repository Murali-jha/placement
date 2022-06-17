class Solution {
public:
    
    
    int solve(string text1, string text2,int n1,int n2,vector<vector<int>> &t){
        if(n1==0 || n2==0){
            return 0;
        }
        
        if(t[n1][n2]!=-1)
            return t[n1][n2];
        
        if(text1[n1-1]==text2[n2-1]){
            return t[n1][n2] = 1 + solve(text1,text2,n1-1,n2-1,t);
        }
        else{
            return t[n1][n2] = max(solve(text1,text2,n1-1,n2,t),solve(text1,text2,n1,n2-1,t));
        }
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> t(n1+1,vector<int>(n2+1,-1));
        
        return solve(text1,text2,n1,n2,t);
    }
};
