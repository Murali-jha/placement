class Solution {
public:
    
    
    int solve(string word1, string word2,int n1,int n2,vector<vector<int>> &t){
        if(n1==0){
            return n2;
        }
        
        if(n2==0){
            return n1;
        }
        
        if(t[n1][n2]!=-1){
            return t[n1][n2];
        }
        
        if(word1[n1-1]==word2[n2-1]){
            return t[n1][n2] = solve(word1,word2,n1-1,n2-1,t);
        }
        else{
            return t[n1][n2] = 1 + min(solve(word1,word2,n1,n2-1,t),min(solve(word1,word2,n1-1,n2,t),solve(word1,word2,n1-1,n2-1,t)));
        }
        
    }
    
    
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> t(n1+1,vector<int>(n2+1,-1));
        
        return solve(word1,word2,n1,n2,t);
    }
};
