class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        vector<int> lps(n,0);
        int i=0;
        int j=1;
        
        while(j<n){
            while(i>0 && needle[i]!=needle[j]){
                i = lps[i-1];
            }
            
            if(needle[i]==needle[j]){
                i++;
            }
            
            lps[j]=i;
            j++;
        }
        
        i=0;j=0;
        
        while(i<haystack.length()){
            while(j>0 && j<n && haystack[i]!=needle[j]){
                j = lps[j-1];
            }
            
            if(j<n && haystack[i]==needle[j]){
                j++;
            }
            
            i++;
            if(j==n){
                return i-n;
            }
        }
        return -1;
    }
};
