bool isPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }

    int solve(string s,int i,int j,vector<vector<int>> &t){
        if(i>=j){
            return 0;
        }
        
        if(isPalindrome(s,i,j)){
            return 0;
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        int mn = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp = 1 + solve(s,i,k,t) + solve(s,k+1,j,t);
            mn = min(mn,temp);
        }
        
        return t[i][j] = mn;
    }


    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        vector<vector<int>> t(n+1,vector<int>(n+1,-1));
        return solve(str,0,n-1,t);
    }
