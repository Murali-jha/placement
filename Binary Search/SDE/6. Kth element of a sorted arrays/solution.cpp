int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=n-1,j=0;
        while(i>=0 && j<m){
            if(arr1[i]>arr2[j]){
                swap(arr1[i],arr2[j]);
            }
            i--;
            j++;
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        if(k<=n){
            return arr1[k-1];
        }
        else{
            k=k-n;
            return arr2[k-1];
        }
    }
