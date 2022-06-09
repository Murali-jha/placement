class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int start=0,end=arr.size()-1;
        int n=arr.size();
        while(start<=end){
            int mid=start+(end-start)/2;
            cout<<start<<" "<<mid<<" "<<end<<endl;
            if(mid>start && mid<end){
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                    return mid;
                }
                else if(arr[mid-1]>arr[mid])
                        end=mid-1;
                else start=mid+1;
            }
            else if(mid==start)
            {
                if(mid+1< n && arr[mid]>arr[mid+1])
                        return mid;
                else start=mid+1;
            }
            else if(mid==end){
                if(end-1>=0 && arr[mid]>arr[end-1])
                        return mid;
                else end=mid-1;
            }
        }
        return n-1;
    }
};
