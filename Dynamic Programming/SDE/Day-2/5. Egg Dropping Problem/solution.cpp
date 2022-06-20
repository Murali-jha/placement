int solve(int n,int k,vector<vector<int>> &t){
        if(k==0 || k==1){
            return k;
        }
        
        if(n==1){
            return k;
        }
        
        if(t[n][k]!=-1){
            return t[n][k];
        }
        
        int mn = INT_MAX;
        for(int i=1;i<=k;i++){
            int temp = 1 + max(solve(n-1,i-1,t),solve(n,k-i,t));
            mn = min(mn,temp);
        }
        
        return t[n][k] = mn;
    }
    
    
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> t(n+1,vector<int>(k+1,-1));
        return solve(n,k,t);
    }
