int findKRotation(int arr[], int n) {
	    // code here
	    int start = 0,end = n-1;
	    while(start<=end){
	        
	        if(arr[start]<arr[end]){
	            return start;
	        }
	        int mid = start + (end-start)/2;
	        int next = (mid+1)%n;
	        int prev = (mid+n-1)%n;
	        if(arr[prev]>=arr[mid] && arr[next]>=arr[mid]){
	            return mid;
	        }
	        else if(arr[start]<=arr[mid]){
	            start = mid+1;
	        }
	        else{
	            end = mid-1;
	        }
	    }
	    return 0;
	}
