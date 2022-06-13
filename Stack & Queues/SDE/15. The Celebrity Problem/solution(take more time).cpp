int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int in[n] = {0};
        int out[n] = {0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]==1){
                    out[i]++;
                    in[j]++;
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(in[i]==n-1 && out[i]==0){
                return i;
            }
        }
        return -1;
    }
