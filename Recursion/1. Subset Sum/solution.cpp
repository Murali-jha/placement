void sum(vector<int> arr,int n,vector<int> &ans,int s,int i){
        if(i>=n){
            ans.push_back(s);
            return;
        }
        
        sum(arr,n,ans,s+arr[i],i+1);
        sum(arr,n,ans,s,i+1);
    }

    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        sum(arr,n,ans,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
