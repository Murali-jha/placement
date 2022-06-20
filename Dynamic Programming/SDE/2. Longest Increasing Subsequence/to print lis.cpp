class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(nums[j]>nums[i] && lis[j]<=lis[i]){
                    lis[j] = lis[i]+1;
                }
            }
        }
        
        
        
        int mx=  INT_MIN;
        int ind;
        for(int i = 0;i<n;i++){
            if(lis[i]>mx){
                mx = lis[i];
                ind = i;
            }
        }
        
        //to print longest increasing subsequence
        vector<int>ans;
        ans.push_back(nums[ind]);
        int curr = lis[ind]-1;
        ind--;
        while(ind>=0){
            if(lis[ind]==curr){
                ans.push_back(nums[ind]);
                curr =  curr-1;
            }
            ind--;
        }
        reverse(lis.begin(),lis.end());
        for(auto it:ans){
            cout<<it<<" ";
        }
        
        
        
        return 0;
    }
};
