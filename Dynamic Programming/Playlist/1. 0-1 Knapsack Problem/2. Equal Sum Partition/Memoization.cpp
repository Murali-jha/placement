int solve(int n, int arr[],int sum,vector<vector<int>> &t){
        if(sum==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        
        if(t[n][sum]!=-1){
            return t[n][sum];
        }
        
        if(arr[n-1]<=sum){
            return t[n][sum] = solve(n-1,arr,sum-arr[n-1],t) || solve(n-1,arr,sum,t);
        }
        else{
            return t[n][sum] = solve(n-1,arr,sum,t);
        }
    }

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
        return solve(n,arr,sum/2,t);
    }
