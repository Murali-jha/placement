#include<queue>

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;
    for(auto it:q){
        if(it.size()>1){
            pq.push(it[1]);
        }
        else{
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    return ans;
}
