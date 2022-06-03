#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int x)
{
	// Write your code here 
    long long int n = (long long int)x;
	long long int s = n*(n+1)/2;
    long long int p = n*(2*n+1)*(n+1)/6;
    
    for(int i=0;i<n;i++){
        s -= (long long int)(arr[i]);
        p -= (long long int)(arr[i]*arr[i]);
    }
    
    int miss = (s + (p/s))/2;
    int repeating  = miss - s;
    
    return {miss,repeating};
}

