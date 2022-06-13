class Solution {
public:
    bool isSafe(vector<vector<int>> &grid,int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==2 || grid[i][j]==0){
            return false;
        }
        return true;
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int ans = 0;
        vector<int> row =  {-1,1,0,0};
        vector<int> col = {0,0,-1,1};
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j,1});
            }
        }
        
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int t = q.front()[2];
            q.pop();
            
            
            for(int i=0;i<4;i++){
                if(isSafe(grid,x+row[i],y+col[i],m,n)){
                    ans = max(ans,t);
                    grid[x+row[i]][y+col[i]]=2;
                    q.push({x+row[i],y+col[i],t+1});
                }
            }
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
