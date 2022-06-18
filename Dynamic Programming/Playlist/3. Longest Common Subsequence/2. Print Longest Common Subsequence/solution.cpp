string lcs(string x, string y, int m, int n)
    {
        //code here
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        
        for(int i=0;i<=n;i++){
            t[0][i] = 0;
        }
        
        for(int i=0;i<=m;i++){
            t[i][0] = 0;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        for(auto it:t){
            for(auto it1:it){
                cout<<it1<<" ";
            }
            cout<<endl;
        }
        
        
        int i=m,j=n;
        string s;
        while(i>0 && j>0){
            if(x[i-1]==y[j-1]){
                s.push_back(x[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i-1][j]>t[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
