class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0,count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                count0++;
            else if(nums[i]==1)
                count1++;
            else
                count2++;
        }
        
        int k=0;
        while(count0--)
            nums[k++] = 0;
        while(count1--)
            nums[k++] = 1;
        while(count2--)
            nums[k++] = 2;
    }
};
