#include<bits/stdc++.h>

using namespace std;



bool isSafe(int arr[],int mid,int n,int k){
	int cows=  1;
	int last = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]-last>=mid){
			cows++;
			last = arr[i];
		}
	}
	if(cows>=k){
		return true;
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		
		sort(arr,arr+n);
		
		int low = 0;
		int high  = arr[n-1] - arr[0];
		int ans = -1;
		while(low<=high){
			int mid = low + (high-low)/2;
			if(isSafe(arr,mid,n,k)){
				ans = mid;
				low = mid+1;
			}
			else{
				high  = mid-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
