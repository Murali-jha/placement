class Solution {
public:
    bool isSubsequence(string s, string s2) {
        int x = s.length();
        int y = s2.length();
        int t[x+1][y+1];
        for(int i=0;i<=x;i++){
            t[i][0] = 0;
        }
        
        for(int i=1;i<=y;i++){
            t[0][i] = 0;
        }
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s[i-1] == s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        if(t[x][y] == x)
            return true;
        else{
            return false;
        }
    }
};
