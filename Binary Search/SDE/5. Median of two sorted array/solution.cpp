class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        int i = n-1;
        int j = 0;
        while(i>=0 && j<m){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
            }
            i--;
            j++;
        }
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int x = n + m;
        cout<<x<<endl;
        if(x%2==0){
            int temp1 = (x/2);
            int temp2 = (x/2)-1;
            if(temp2>=n){
                temp1 = temp1 - n;
                temp2 = temp2 - n;
                return (nums2[temp1] + nums2[temp2])/2.0;
            }
            else if(temp1>=n){
                cout<<"yeah"<<endl;
                temp1 = temp1 - n;
                return (nums2[temp1] + nums1[temp2])/2.0;
            }
            return (nums1[temp1] + nums1[temp2])/2.0;
        }
        else{
            int temp1 = (x/2);
            if(temp1<n){
                return nums1[temp1];
            }
            temp1 = temp1-n;
            return nums2[temp1];
        }
        return 0;
    }
};
