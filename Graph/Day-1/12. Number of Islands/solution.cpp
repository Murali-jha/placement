class Solution {
public:
    
    
    void setIsLands(vector<vector<char>>& grid,int i,int j,int m,int n){
        if(i>=m || i<0 || j<0 || j>=n || grid[i][j]!='1')
            return;
        
        grid[i][j]='2';
        setIsLands(grid,i-1,j,m,n);
        setIsLands(grid,i,j-1,m,n);
        setIsLands(grid,i+1,j,m,n);
        setIsLands(grid,i,j+1,m,n);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    setIsLands(grid,i,j,m,n);
                    ans++;
                }
            }
        }
        return ans;
    }
};
