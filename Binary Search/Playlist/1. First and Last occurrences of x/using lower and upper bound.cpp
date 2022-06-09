vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        vector<int> ans;
        int ind = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        
        if(ind!=n && arr[ind]==x){
            ans.push_back(ind);
        }
        else{
            ans.push_back(-1);
            return ans;
        }
        
        ind = upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        ind--;
        ans.push_back(ind);
        return ans;
    }
