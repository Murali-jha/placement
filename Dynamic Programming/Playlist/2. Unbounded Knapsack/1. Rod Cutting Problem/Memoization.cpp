int solve(int price[],int n,int total,int wt[],vector<vector<int>> &t){
        if(n==0 || total==0){
            return 0;
        }
        
        if(t[n][total]!=-1){
            return t[n][total];
        }
        
        if(wt[n-1]<=total){
            t[n][total] = max(price[n-1] +solve(price,n,total-wt[n-1],wt,t),solve(price,n-1,total,wt,t));
        }
        else{
            return t[n][total] = solve(price,n-1,total,wt,t);
        }
    }
  
    int cutRod(int price[], int n) {
        //code here
        int wt[n];
        for(int i=0;i<n;i++){
            wt[i] = i+1;
        }
        
        vector<vector<int>> t(n+1,vector<int>(n+1,-1));
        return solve(price,n,n,wt,t);
    }
