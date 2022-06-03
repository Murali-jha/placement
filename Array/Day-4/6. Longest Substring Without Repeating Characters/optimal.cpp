class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int ans = 0;
        map<char,int> mp;
        while(right<s.length()){
            if(mp.find(s[right])!=mp.end()){
                left = max(mp[s[right]]+1,left);
            }
            ans = max(ans,right-left+1);
            mp[s[right]] = right;
            right++;
        }
        return ans;
    }
};
