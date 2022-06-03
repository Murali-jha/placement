class Solution {
public:
    
    int move(int i,int j,int m,int n,vector<vector<int>> &t){
        
        if(i==m-1 && j==n-1)
            return 1;
        
        
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        return t[i][j] = move(i+1,j,m,n,t) + move(i,j+1,m,n,t);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m,vector<int>(n,-1));
        
        int num =  move(0,0,m,n,t);
        return num;
    }
};
