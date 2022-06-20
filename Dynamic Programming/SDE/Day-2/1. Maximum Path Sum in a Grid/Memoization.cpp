class Solution {
public:
    
    
    int solve(vector<vector<int>>& grid, int i,int j,vector<vector<int>>& t){
        if(i==0 && j==0){
            return grid[i][j];
        }
        
        if(i<0 || j<0){
            return 1e9;
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        return t[i][j] = grid[i][j] + min(solve(grid,i-1,j,t),solve(grid,i,j-1,t));
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        return solve(grid,m-1,n-1,t);
    }
};
