class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack==needle){
            return 0;
        }
        if(needle.length()>=haystack.length())
            return -1;
        
        
        int k = needle.length();
        for(int i=0;i<=haystack.length()-k;i++){
            if(haystack.substr(i,k)==needle){
                return i;
            }
        }
        return -1;
    }
};
