class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        deque<int> q;
        vector<int> ans;
        while(j<nums.size()){
            if(q.empty()){
                q.push_back(j);
            }
            else{
                while(!q.empty() && nums[q.back()]<nums[j]){
                    q.pop_back();
                }
                q.push_back(j);
            }
            
            if(j-i+1==k){
                ans.push_back(nums[q.front()]);
                if(q.front()==i){
                    q.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
