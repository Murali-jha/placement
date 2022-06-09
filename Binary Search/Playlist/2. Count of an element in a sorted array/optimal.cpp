int count(int arr[], int n, int x) {
	    // code here
	    int ind = lower_bound(arr,arr+n,x)-arr;
	    if(ind!=n && arr[ind]==x){
	        
	    }
	    else{
	        return 0;
	    }
	    int ind1 = upper_bound(arr,arr+n,x)-arr;
	    ind1--;
	    
	    return ind1-ind+1;
	}
