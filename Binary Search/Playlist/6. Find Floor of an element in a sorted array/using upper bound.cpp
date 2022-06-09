int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        long long ind = upper_bound(v.begin(),v.end(),x) - v.begin();
        ind--;
        if(ind<0){
            return -1;
        }
        else{
            return ind;
        }
    }
