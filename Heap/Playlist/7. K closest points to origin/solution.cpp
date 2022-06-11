class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(auto it: points){
            int u = it[0];
            int v = it[1];
            pq.push({(u*u + v*v),u,v});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top()[1],pq.top()[2]});
            pq.pop();
        }
        return ans;
    }
};
