int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i = 1,j=0;
    	int platform = 1;
    	int ans = 1;
    	
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        platform++;
    	        i++;
    	    }
    	    else if(arr[i]>dep[j]){
    	        platform--;
    	        j++;
    	    }
    	    ans = max(ans,platform);
    	}
    	return ans;
    }
