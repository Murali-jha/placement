int solve(int w, int wt[], int val[], int n, vector<vector<int>> &t){
        if(n==0 || w==0){
            return 0;
        }
        
        if(t[n][w]!=-1){
            return t[n][w];
        }
        
        
        if(wt[n-1]<=w){
            return t[n][w] = max(val[n-1]+solve(w-wt[n-1],wt,val,n-1,t),solve(w,wt,val,n-1,t));
        }
        else{
            return t[n][w] = solve(w,wt,val,n-1,t);
        }
    }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> t(n+1,vector<int>(W+1,-1));
       return solve(W,wt,val,n,t);
    }
