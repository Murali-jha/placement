int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int k = 0,id = 0;
        for(int i=0;i<n;i++){
            bool check =true;
            for(int j=0;j<n;j++){
                if(M[i][j]!=0){
                    check = false;
                    break;
                }
                check = true;
            }
            
            if(check){
                k++;
                if(k>1){
                    break;
                }
                else{
                    id = i;
                }
            }
        }
        
        if(k==1){
            return id;
        }
        else{
            return -1;
        }
    }
