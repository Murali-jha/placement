#include<algorithm>

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> v;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            v.push_back(matrix[i][j]);
        }
    }
    
    sort(v.begin(),v.end());
    
    int x = v.size();
    if(x%2==0){
        int temp = x/2;
        return( v[temp-1] + v[temp])/2;
    }
    else{
        return v[(x/2)];
    }
    
}
