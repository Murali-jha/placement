int solve(string s1, string s2, int n, int m,vector<vector<int>> &t,int count){
        if(n==0 || m==0){
            return count;
        }
        
        // if(t[n][m]!=-1){
        //     return t[n][m];
        // }
        
        int count1 = 0;
        if(s1[n-1]==s2[m-1]){
            count = solve(s1,s2,n-1,m-1,t,count+1);
        }
        else    
            count1 = max(solve(s1,s2,n-1,m,t,0),solve(s1,s2,n,m-1,t,0));
            
        return max(count,count1);
    }
    
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> t(n+1,vector<int>(m+1,-1));
        int res = solve(S1,S2,n,m,t,0);
        return res;
    }
