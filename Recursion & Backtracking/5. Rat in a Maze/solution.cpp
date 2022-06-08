bool isSafe(vector<vector<int>> m,int n,int i,int j){
        if(i<0 || j<0 || i>n-1 || j>n-1 || m[i][j]==0){
            return false;
        }
        return true;
    }
    
    void solve(vector<vector<int>> &m, int n,int i,int j,vector<string> &ans,string s){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        
        
        int row[] = {1,0,0,-1};
        int col[] = {0,-1,1,0};
        char dir[] = {'D','L','R','U'};
        
        
        for(int ind=0;ind<4;ind++){
            int x = i + row[ind];
            int y = j + col[ind];
            if(isSafe(m,n,x,y)){
                s.push_back(dir[ind]);
                m[i][j] = 0;
                solve(m,n,x,y,ans,s);
                m[i][j] = 1;
                s.pop_back();
            }
        }
        
    }
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0 || m[n-1][n-1]==0){
            return ans;
        }
        string s = "";
        solve(m,n,0,0,ans,s);
        return ans;
    }
