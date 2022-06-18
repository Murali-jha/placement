class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {
        int x = str1.length();
        int y = str2.length();
        int t[x+1][y+1];
        for(int i=0;i<=x;i++){
            t[i][0] = 0;
        }
        
        for(int i=1;i<=y;i++){
            t[0][i] = 0;
        }
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(str1[i-1] == str2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        
        int i=x;
        int j=y;
        string s = "";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i][j-1]>t[i-1][j]){
                    s.push_back(str2[j-1]);
                    j--;
                }
                else{
                    s.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        
        
        while(i>0){
            s.push_back(str1[i-1]);
            i--;
        }
        
        while(j>0){
            s.push_back(str2[j-1]);
            j--;
        }
        
        reverse(s.begin(),s.end());
        return s;
    }
};
