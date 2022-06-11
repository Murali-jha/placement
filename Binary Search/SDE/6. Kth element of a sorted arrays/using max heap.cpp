int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<int> max_heap;
        for(int i=0;i<n;i++){
            max_heap.push(arr1[i]);
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        
        for(int i=0;i<m;i++){
            max_heap.push(arr2[i]);
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        
        return max_heap.top();
    }
