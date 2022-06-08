class Solution {
public:
    
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
    
    void solve(int col,int n, vector<vector<string>> &queenArrangements,vector<int> &possibleQueenArrangement,vector<string> &temp,string s){
        if(col==n){
           queenArrangements.push_back(temp);
            return;
        }
        
        
        for(int row = 0;row<n;row++){
            string str = s;
            if(isSafe(row,possibleQueenArrangement)){
                possibleQueenArrangement.push_back(row);
               str[row]  = 'Q';
               temp.push_back(str); solve(col+1,n,queenArrangements,possibleQueenArrangement,temp,s);
                temp.pop_back();
                possibleQueenArrangement.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> queenArrangements;
        vector<int> possibleQueenArrangement;
        vector<string> temp;
        string s = "";
        for(int i=0;i<n;i++){
            s+='.';
        }
        solve(0,n,queenArrangements,possibleQueenArrangement,temp,s);
        return queenArrangements;
        
    }
};
