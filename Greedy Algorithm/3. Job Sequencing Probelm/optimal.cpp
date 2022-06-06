bool static comp(Job a,Job b){
        if(a.profit==b.profit){
            return a.dead<b.dead;
        }
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int maxDead = INT_MIN;
        for(int i=0;i<n;i++){
            maxDead = max(arr[i].dead,maxDead);
        }
        
        vector<int> v(maxDead+1,-1);
        sort(arr,arr+n,comp);
        
        
        int count = 0;
        int ans=  0;
        for(int i=0;i<n;i++){
            for (int j = arr[i].dead; j > 0; j--) {
                if (v[j] == -1) {
                   v[j] = i;
                   count++;
                   ans += arr[i].profit;
                   break;
                }
             }
        }
        return {count,ans};
    }
