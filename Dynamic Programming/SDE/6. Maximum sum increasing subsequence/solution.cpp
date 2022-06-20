int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> is;
	    for(int i=0;i<n;i++){
	        is.push_back(arr[i]);
	    }
	    
	    for(int j=1;j<n;j++){
	        for(int i=0;i<j;i++){
	            if(arr[j]>arr[i] && is[i] + arr[j]>is[j]){
	                is[j] = is[i] + arr[j];
	            }
	        }
	    }
	    
	    
	    int ans = INT_MIN;
	    for(auto it:is){
	        ans = max(ans,it);
	    }
	    
	    return ans;
	}  
