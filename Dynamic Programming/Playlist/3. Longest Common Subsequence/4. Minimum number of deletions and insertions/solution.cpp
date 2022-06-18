int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.length();
	    int n = str2.length();
	    int t[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
                else if(str1[i-1]==str2[j-1]){
                    t[i][j] = t[i-1][j-1] + 1;
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return (m+n-2*t[m][n]);
	} 
