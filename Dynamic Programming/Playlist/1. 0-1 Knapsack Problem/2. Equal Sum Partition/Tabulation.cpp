int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        vector<vector<int>> t(n+1,vector<int>((sum/2)+1,-1));
        
        for(int i=1;i<=sum/2;i++){
            t[0][i] = 0;
        }
        
        for(int i=0;i<=n;i++){
            t[i][0] = 1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
                if(arr[i-1]<=j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum/2];
    }
