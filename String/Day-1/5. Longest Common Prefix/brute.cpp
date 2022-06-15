class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        else if(strs.size()==0){
            return "";
        }
        
        int i = 0;
        string ans = "";
        while(i<strs[0].size()){
            int j = 1;
            char target = strs[0][i];
            while(j<strs.size()){
                if(strs[j].length()==i){
                    return ans;
                }
                if(strs[j-1][i]!=strs[j][i]){
                    return ans;
                }
                
                j++;
            }
            
            ans += target;
            i++;
        }
        return ans;
    }
};
