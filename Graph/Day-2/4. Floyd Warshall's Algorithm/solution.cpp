void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int m = matrix.size();
	    
	    for(int k=0;k<m;k++){
	        for(int i=0;i<m;i++){
	            for(int j=0;j<m;j++){
	                if(matrix[i][k]==-1 || matrix[k][j]==-1){
	                    continue;
	                }
	                else if(matrix[i][j]==-1){
	                    matrix[i][j] = matrix[i][k] + matrix[k][j];
	                }
	                else{
	                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	                }
	            }
	        }
	    }
	}
