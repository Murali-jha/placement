#include <algorithm>

bool static comp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> v;
    int n = start.size();
    for(int i=0;i<n;i++){
        v.push_back({start[i],finish[i]});
    }
    sort(v.begin(),v.end(),comp);
    int limit = v[0].second;
    int ans = 1;
    for(int i=1;i<n;i++){
        if(v[i].first>=limit){
            ans++;
            limit = v[i].second;
        }
    }
    return ans;
}
