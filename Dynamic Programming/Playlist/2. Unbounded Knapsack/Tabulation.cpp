int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> t(n+1,vector<int>(w+1,-1));
        for(int i=0;i<=w;i++){
            t[0][i] = 0;
        }
        for(int i=0;i<=n;i++){
            t[i][0] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(wt[i-1]<=j){
                    t[i][j] = max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][w];
    }
