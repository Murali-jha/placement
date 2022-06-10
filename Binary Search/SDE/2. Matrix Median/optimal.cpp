int countSmallerThan(vector<int> v,int x){
    int low=  0;
    int high = v.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]<=x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}



int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 0;
    int high = 1e9;
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    while(low<=high){
        int mid = low + (high-low)/2;
        int count = 0;
        for(int i=0;i<n;i++){
            count+=countSmallerThan(matrix[i],mid);
        }
        
        if(count <= (m*n)/2){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
