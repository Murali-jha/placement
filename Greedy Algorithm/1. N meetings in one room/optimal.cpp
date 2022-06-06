bool static comp(pair<int,int> a, pair<int,int> b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),comp);
        int limit = v[0].second;
        int count = 1;
        
        for(int i=1;i<n;i++){
            if(v[i].first>limit){
                count++;
                limit = v[i].second;
            }
        }
        return count;
    }
