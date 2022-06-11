#include<set>
#include<queue>
#include<algorithm>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    priority_queue<vector<int>> pq;
    vector<int> ans;
    if(k==0)
        return ans;
    pq.push({a[n-1]+b[n-1],n-1,n-1});
    set<pair<int,int>> s;
    s.insert({n-1,n-1});
    while(ans.size()!=k){
        ans.push_back(pq.top()[0]);
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();
        if(!s.count({x-1,y})){
            pq.push({a[x-1]+b[y],x-1,y});
            s.insert({x-1,y});
        }
        if(!s.count({x,y-1})){
            pq.push({a[x]+b[y-1],x,y-1});
            s.insert({x,y-1});
        }
    }
    return ans;
}


//#include<set>
// #include<queue>
// #include<algorithm>

// vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
// 	// Write your code here.
//     sort(a.begin(),a.end());
//     sort(b.begin(),b.end());
    
//     priority_queue<vector<int>> pq;
//     vector<int> ans;
//     if(k==0)
//         return ans;
//     pq.push({a[n-1]+b[n-1],n-1,n-1});
//     set<pair<int,int>> s;
//     s.insert({n-1,n-1});
//     while(ans.size()!=k){
//         ans.push_back(pq.top()[0]);
//         int x = pq.top()[1];
//         int y = pq.top()[2];
//         pq.pop();
//         if(x>0 && !s.count({x-1,y})){
//             pq.push({a[x-1]+b[y],x-1,y});
//             s.insert({x-1,y});
//         }
//         if(y>0 && !s.count({x,y-1})){
//             pq.push({a[x]+b[y-1],x,y-1});
//             s.insert({x,y-1});
//         }
//     }
//     return ans;
// }
