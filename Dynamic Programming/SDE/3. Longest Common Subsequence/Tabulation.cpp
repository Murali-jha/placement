class Solution {
public:
    

    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> t(n1+1,vector<int>(n2+1,-1));
        for(int i=0;i<=n2;i++){
            t[0][i] = 0;
        }
        
        for(int i=0;i<=n1;i++){
            t[i][0] = 0;
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n1][n2];
    }
};
