class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>, compare> pq;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(!pq.empty()){
            auto [u,v] = pq.top();
            for(int i=0;i<u;i++){
                ans.push_back(v);
            }
            pq.pop();
        }
        return ans;
    }
    
    struct compare{
        bool operator()(pair<int,int> p1,pair<int,int> p2){
            if (p1.first==p2.first){
                return p1.second<p2.second;
            }
            return p1.first>p2.first;
        
        }
    };
};
