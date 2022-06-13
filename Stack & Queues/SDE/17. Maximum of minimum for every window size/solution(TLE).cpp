#include<queue>

vector<int> maxMinWindow(vector<int> nums, int n) {
    // Write your code here.
    vector<int> ans;
    for(int k=1;k<=n;k++){
        int i=0,j=0;
        deque<int> q;
        int mx = INT_MIN;
        while(j<nums.size()){
            if(q.empty()){
                q.push_back(j);
            }
            else{
                while(!q.empty() && nums[q.back()]>nums[j]){
                    q.pop_back();
                }
                q.push_back(j);
            }
            
            if(j-i+1==k){
                mx = max(mx,nums[q.front()]);
                if(q.front()==i){
                    q.pop_front();
                }
                i++;
            }
            j++;
        }
        ans.push_back(mx);
    }
    return ans;
    
}
