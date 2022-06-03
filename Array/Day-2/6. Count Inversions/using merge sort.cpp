#include <bits/stdc++.h> 


void merge(int l,int mid,int r,long long &ans,long long *arr){
    vector<long long> temp;
    int i = l;
    int j = mid;
    while(i<mid && j<=r){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            ans += (long long)(mid-i);
            temp.push_back(arr[j++]);
        }
    }
    
    while(i<mid){
        temp.push_back(arr[i++]);
    }
    
    while(j<=r){
        temp.push_back(arr[j++]);
    }
    
    int k = 0;
    for(i = l;i<=r;i++){
        arr[i] = temp[k++];
    }
}

void mergeSort(int l,int r, long long &ans,long long arr[]){
    int mid = 0;
    if(l<r){
        mid = (l+r)/2;
        mergeSort(l,mid,ans,arr);
        mergeSort(mid+1,r,ans,arr);
        merge(l,mid+1,r,ans,arr);
    }
}



long long getInversions(long long *arr, int n){
    // Write your code here.
    long long ans = 0;
    mergeSort(0,n-1,ans,arr);
    return ans;
}
