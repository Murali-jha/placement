class Solution {
public:
    
    
    
    string longestPalindrome(string s) {
        int size = 1;

        int beg = 0;
        
        
        for(int i=0;i<s.length();i++){
            
            int start = i;
            int end = i+1;
            

            //even
            while(start>=0 && end<s.length() && s[start]==s[end]){
                if(end-start+1>size){
                    beg = start;
                    size = end-start+1;
                }
                start--;
                end++;
            }
            
            start = i-1;
            end = i+1;
            
            //odd
            while(start>=0 && end<s.length() && s[start]==s[end]){
                if(end-start+1>size){
                    beg = start;
                    size = end-start+1;
                }
                start--;
                end++;
            }
        }
        
        string ans = "";
        ans = s.substr(beg,size);
        return ans;
    }
};
