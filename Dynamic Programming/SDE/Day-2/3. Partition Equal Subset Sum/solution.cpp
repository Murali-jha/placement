class Solution {
public:
    
    bool subsetSum(vector<int> arr,int n,int sum){
        bool t[n+1][sum+1];
        
        t[0][0] = true;
        
        for(int i=1;i<=sum;i++){
            t[0][i] = false;
        }
        
        for(int i=1;i<=n;i++){
            t[i][0] = true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2!=0){
            return false;
        }
        else{
            return subsetSum(nums,n,sum/2);
        }
    }
};
