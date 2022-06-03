class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(ele==nums[i]){
                count++;
            }
            else if(count==0){
                ele = nums[i];
                count=1;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};
