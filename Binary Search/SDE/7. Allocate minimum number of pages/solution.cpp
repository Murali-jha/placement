bool isSafe(int a[],int n,int m,int mid){
        int students = 1;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(a[i]>mid){
                return false;
            }
            sum += a[i];
            if(sum>mid){
                students++;
                sum = a[i];
            }
            if(students>m){
                return false;
            }
        }
        return true;
    }
    
    
    
    int findPages(int a[], int n, int m) 
    {
        //code here
        int low = 0;
        int high = 0;
        for(int i=0;i<n;i++){
            high += a[i];
        }
        int ans = 0;
        while(low<=high){
            int mid=  (low) + (high-low)/2;
            
            if(isSafe(a,n,m,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
