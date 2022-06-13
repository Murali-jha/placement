class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> ans;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            
            int x = s.empty()?-1:s.top();
            mp[nums2[i]] = x;
            s.push(nums2[i]);
        }
        
        for(auto it:nums1){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};
