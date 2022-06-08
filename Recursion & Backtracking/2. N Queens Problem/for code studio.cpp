
bool isSafe(int row,vector<int> possibleQueenArrangement){
        //row safety
        for(auto it:possibleQueenArrangement){
            if(it==row){
                return false;
            }
        }
        
        //upper diagonal safety;
        int temp = row-1;
        for(int i = possibleQueenArrangement.size()-1;i>=0;i--){
            if(temp==possibleQueenArrangement[i]){
                return false;
            }
            temp--;
        }
        
        
        //lower diagonal safety;
        temp = row+1;
        for(int i = possibleQueenArrangement.size()-1;i>=0;i--){
            if(temp==possibleQueenArrangement[i]){
                return false;
            }
            temp++;
        }
        return true;
    }
    
    void solve(int col,int n, vector<vector<int>> &queenArrangements,vector<int> &possibleQueenArrangement,vector<int> &temp){
        if(col==n){
           queenArrangements.push_back(temp);
            return;
        }
        
        
        for(int row = 0;row<n;row++){
            if(isSafe(row,possibleQueenArrangement)){
                for(int i=0;i<n;i++){
                    if(i==row){
                        temp.push_back(1);
                    }
                    else
                        temp.push_back(0);
                }
                possibleQueenArrangement.push_back(row);
                solve(col+1,n,queenArrangements,possibleQueenArrangement,temp);
                for(int i=0;i<n;i++){
                    temp.pop_back();
                }
                possibleQueenArrangement.pop_back();
            }
        }
    }

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
        vector<vector<int>> queenArrangements;
        vector<int> possibleQueenArrangement;
        vector<int> temp;
        solve(0,n,queenArrangements,possibleQueenArrangement,temp);
        return queenArrangements;
}
