int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int ans = 0;
        int count  = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            count += a[i];
            if(count==0){
                ans = i+1;
            }
            else{
                if(mp.find(count)!=mp.end()){
                    ans = max(ans,i-mp[count]);
                }
                else{
                    mp[count] = i;
                }
            }
        }
        
        
        return ans;
        
    }
