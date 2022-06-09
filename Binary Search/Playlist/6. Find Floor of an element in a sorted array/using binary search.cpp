int findFloor(vector<long long> arr, long long n, long long x){
        
        // Your code here
        long long left = 0, right = n-1;
        int ans = -1;
        while(left<=right){
            long long mid = left + (right-left)/2;
            if(arr[mid]==x){
                return mid;
            }
            else if(arr[mid]<x){
                ans = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return ans;
    }
