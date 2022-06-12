vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans(n);
        int j = 0;
        stack<long long> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }
            long long x = s.empty()?-1:s.top();
            ans[j++] = (x);
            s.push(arr[i]);
        }
        return ans;
    }
