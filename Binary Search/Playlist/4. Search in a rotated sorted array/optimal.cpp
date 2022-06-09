class Solution {
public:
    
    
    int bs(vector<int> nums,int i,int j,int x){
        while(i<=j){
            int mid= i + (j-i)/2;
            if(nums[mid]==x){
                return mid;
            }
            else if(nums[mid]<x){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return -1;
    }
    
    
    int search(vector<int>& arr, int target) {
        int left = 0,right= arr.size()-1;
        int n = arr.size();
        int temp = -1;
        while(left<=right){
            if(arr[left]<arr[right]){
                temp = left;
                break;
            }
            int mid = left + (right-left)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
                temp = mid;
                break;
            }
            else if(arr[left]<=arr[mid]){
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        
        //cout<<temp<<endl;
        int x = bs(arr,0,temp-1,target);
        cout<<x<<endl;
        if(x==-1){
            return bs(arr,temp,n-1,target);
        }
        return x;
    }
};
