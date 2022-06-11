int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        //using heap
        
        priority_queue<int> max_heap;
        
        for(int i=0;i<=r;i++){
            max_heap.push(arr[i]);
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        
        return max_heap.top();
    }
