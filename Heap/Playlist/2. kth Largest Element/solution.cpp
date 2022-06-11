vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int,vector<int>,greater<int>> min_heap;
	    
	    for(int i=0;i<n;i++){
	        min_heap.push(arr[i]);
	        if(min_heap.size()>k){
	            min_heap.pop();
	        }
	    }
	    
	    vector<int> ans(k);
	    int j = k-1;
	    while(k--){
	        ans[j--] = min_heap.top();
	        min_heap.pop();
	    }
	    return ans;
	}
