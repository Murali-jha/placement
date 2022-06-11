long long solve(long long a[],long long n,long long k){
        priority_queue<long long> pq;
        for(int i=0;i<n;i++){
            pq.push(a[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        return pq.top();
    }
    
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long first = solve(A,N,K1);
        long long second = solve(A,N,K2);
        long long ans = 0;
        for(int i=0;i<N;i++){
            if(A[i]>first && A[i]<second){
                ans += A[i];
            }
        }
        return ans;
    }
