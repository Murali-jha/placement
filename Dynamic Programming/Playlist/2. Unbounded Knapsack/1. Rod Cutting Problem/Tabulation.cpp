int cutRod(int price[], int n) {
    int wt[n];
    for(int i=0;i<=n;i++){
        wt[i]=i+1;
    }
    int t[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j==0 || i==0){
                t[i][j]=0;
            }
            else if(wt[i-1]<=j){
                t[i][j] = max((price[i-1] + t[i][j-wt[i-1]]),t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][n];
}
