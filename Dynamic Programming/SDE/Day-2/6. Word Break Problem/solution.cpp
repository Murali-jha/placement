int solve(string A, vector<string> &B,vector<vector<int>> &t,int i,int j){
        if(i>j){
            return 0;
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        string temp;
        for(int x = i;x<=j;x++){
            temp.push_back(A[x]);
        }
        
        if(find(B.begin(),B.end(),temp)!=B.end()){
            return 1;
        }
        
        
        for(int k=i;k<=j-1;k++){
            t[i][j] = solve(A,B,t,i,k) && solve(A,B,t,k+1,j);
            if(t[i][j]){
                return 1;
            }
        }
        
        return 0;
        
    }


    int wordBreak(string A, vector<string> &B) {
        //code here
        vector<vector<int>> t(A.length()+1,vector<int>(A.length()+1,-1));
        return solve(A,B,t,0,A.length()-1);
    }
