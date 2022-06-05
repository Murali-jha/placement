class Solution {
public:
    int trap(vector<int>& height) {
        int ans=  0;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int left = 0,right = height.size()-1;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>leftMax){
                    leftMax = height[left];
                }
                else{
                    ans += (leftMax - height[left]);
                }
                left++;
            }
            else{
                if(height[right]>rightMax){
                    rightMax = height[right];
                }
                else{
                    ans += (rightMax - height[right]);
                }
                right--;
            }
        }
        return ans;
    }
};
