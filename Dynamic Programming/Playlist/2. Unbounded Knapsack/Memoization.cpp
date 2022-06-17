int solve(int n,int w,int val[],int wt[],vector<vector<int>> &t){
        if(n==0 || w==0){
            return 0;
        }
        
        if(t[n][w]!=-1){
            return t[n][w];
        }
        
        if(wt[n-1]<=w){
            t[n][w] = max(val[n-1]+solve(n,w-wt[n-1],val,wt,t),solve(n-1,w,val,wt,t));
        }
        else{
            t[n][w] = solve(n-1,w,val,wt,t);
        }
    }

    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> t(n+1,vector<int>(w+1,-1));
        return solve(n,w,val,wt,t);
    }
