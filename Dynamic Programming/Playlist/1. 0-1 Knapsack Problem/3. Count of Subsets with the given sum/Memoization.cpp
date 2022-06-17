int solve(vector<int>arr, int sum, int n,vector<vector<int>> &t){
        if(sum==0){
            return true;
        }
        if(n==0){
            return false;
        }
        
        if(t[n][sum]!=-1){
            return t[n][sum];
        }
        
        if(arr[n-1]<=sum){
            return t[n][sum] = solve(arr,sum-arr[n-1],n-1,t) + solve(arr,sum,n-1,t);
        }
        else{
            return t[n][sum] = solve(arr,sum,n-1,t);
        }
    }


    int isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> t(n+1,vector<int>(sum+1,-1));
        return solve(arr,sum,n,t);
    }
