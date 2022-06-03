#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int xor1 =arr[0];
    for(int i=1;i<n;i++){
        xor1 = xor1 ^  arr[i];
    }
    for(int i=1;i<=n;i++){
        xor1 = xor1 ^ i;
    }
    
    int x = 0;
    int y = 0;
    
    int set = xor1 & ~(xor1-1);
    for(int i=0;i<n;i++){
        if(arr[i] & set){
            x = x^arr[i];
        }
        else{
            y = y^arr[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(i & set){
            x = x^i;
        }
        else{
            y = y^i;
        }
    }
    
    int xcount = 0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            xcount++;
        }
    }
    
    if(xcount==0){
        return {x,y};
    }
    return {y,x};
}
