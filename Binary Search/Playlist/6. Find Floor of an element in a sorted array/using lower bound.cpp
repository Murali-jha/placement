int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        long long ind = lower_bound(v.begin(),v.end(),x) - v.begin();
        if(ind!=n && v[ind]!=x){
            return ind-1;
        }
        if(ind==n)
            return ind-1;
        return ind;
    }
