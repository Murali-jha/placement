vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
        
        
        
        vector<long long> ans;
        queue<long long> q;
        long long int i = 0;
        long long int j = 0;
        while(j<n){
            if(a[j]<0){
                q.push(j);
            }
            if(j-i+1==k){
                if(q.empty()){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(a[q.front()]);
                    if(q.front()==i){
                        q.pop();
                    }
                }
                i++;
            }
            j++;
        }
              return ans;                                   
 }
