// Time Complexity: For the first iteration backward, the second interaction backward and reversal at the end takes O(N) for each, where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(N).

// Space Complexity: Since no extra storage is required. Thus, its complexity is O(1).

class Solution {
public:
    
    void reverse(vector<int> &nums,int i,int j){
        while(i<j){
            swap(nums[i++],nums[j--]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1){
            return;
        }
        int ind1=nums.size()-2;
        while(ind1>=0 && nums[ind1]>=nums[ind1+1])
            ind1--;
        
        if(ind1>=0){
            int ind2 = nums.size()-1;
            while(ind2>=0 && nums[ind1]>=nums[ind2]){
                ind2--;
            }
            swap(nums[ind1],nums[ind2]);
        }
        
        reverse(nums,ind1+1,nums.size()-1);
    }
};
