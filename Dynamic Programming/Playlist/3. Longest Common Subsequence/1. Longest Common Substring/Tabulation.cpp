int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> t(n+1,vector<int>(m+1,-1));
        int res=  0;
        
        for(int i=0;i<=n;i++){
            t[i][0]  = 0;
        }
        
        for(int i=0;i<=m;i++){
            t[0][i] = 0;
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                    res = max(res,t[i][j]);
                }
                else{
                    t[i][j] = 0;
                }
            }
        }
        
        return res;
    }
