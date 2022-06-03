#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
	int xr = 0;
	unordered_map<int,int> mp;
	int ans = 0;
	for(int i=0;i<arr.size();i++){
		xr = xr^arr[i];
		if(xr==x){
			ans++;
		}
		int y = xr^x;
		if(mp.find(y)!=mp.end()){
			ans = ans + mp[y];
		}
		
		mp[xr]++;
	}
	return ans;
}
