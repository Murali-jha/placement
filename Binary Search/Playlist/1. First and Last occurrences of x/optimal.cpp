vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        vector<int> ans;
        
        int temp = -1;
        int left = 0, right = n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(arr[mid]==x){
                temp = mid;
                right = mid-1;
            }
            else if(arr[mid]<x){
                left  = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        
        //cout<<temp<<endl;
        ans.push_back(temp);
        if(temp==-1)
            return ans;
        left = 0, right = n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(arr[mid]==x){
                temp = mid;
                left = mid+1;
            }
            else if(arr[mid]<x){
                left  = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        ans.push_back(temp);
        return ans;
    }
