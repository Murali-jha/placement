class Solution {
public:
    
    int bs(vector<int> nums,int target,int i,int j){
        while(i<=j){
            int mid=  i + (j-i)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();        
        int high = n-1;

        int temp = 0;
        
        while(low<=high){
            if(nums[low]<nums[high]){
                temp = low;
                break;
            }
            int mid=  low + (high-low)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev]){
                temp = mid;
                break;
            }
            else if(nums[low]<=nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        cout<<temp<<endl;
        int x  = bs(nums,target,0,temp-1);
        if(x==-1){
            return bs(nums,target,temp,n-1);
        }
        return x;
    }
};
