int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        //code here
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        
        for(int i=0;i<=n;i++){
            t[0][i] = 0;
        }
        
        for(int i=0;i<=m;i++){
            t[i][0] = 0;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        
        return m+n-t[m][n];
    }
