nt solve(int arr[],int i,int j,vector<vector<int>> &t){
        if(i>=j){
            return 0;
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        int mn = INT_MAX;
        for(int k=i+1;k<=j;k++){
            int temp  = solve(arr,i,k-1,t) + solve(arr,k,j,t) + arr[i-1]*arr[k-1]*arr[j];
            mn = min(mn,temp);
        }
        
        return t[i][j] = mn;
    }



    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> t(N+1,vector<int>(N+1,-1));
        return solve(arr,1,N-1,t);
    }
