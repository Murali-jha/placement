class Solution {
public:
    int minInsertions(string s) {
        string temp = s;
        int n = s.length();
        reverse(temp.begin(),temp.end());
        
        vector<vector<int>> t(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            t[i][0] = 0;
        }
        
        for(int i=0;i<=n;i++){
            t[0][i] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==temp[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return n - t[n][n];
    }
};
