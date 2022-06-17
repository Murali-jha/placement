int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int sum  = 0;
	    for(int i=0;i<n;i++){
	        sum += arr[i];
	    }
	    
	    vector<vector<int>> t(n+1,vector<int>(sum+1,-1));
	    
	    for(int i=1;i<=sum;i++){
	        t[0][i] = 0;
	    }
	    
	    for(int i=0;i<=n;i++){
	        t[i][0] = 1;
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j){
	                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
	            }
	            else{
	                t[i][j] = t[i-1][j];
	            }
	        }
	    }
	    
	    int ans = sum;
	    vector<int> v;
	    for(int i=0;i<=sum/2;i++){
	        if(t[n][i]){
	            v.push_back(i);
	        }
	    }
	    
	    for(auto it:v){
	        ans = min(ans,sum-2*it);
	    }
	    return ans;
	} 
