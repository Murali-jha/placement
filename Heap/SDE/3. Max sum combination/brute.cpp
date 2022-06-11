#include<queue>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(auto it:a){
        for(auto it1:b){
            pq.push(it+it1);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    vector<int> ans(k);
    k--;
    while(!pq.empty()){
        ans[k--] = pq.top();
        pq.pop();
    }
    
    return ans;
}
