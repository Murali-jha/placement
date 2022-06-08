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
    
    void solve(int col,int n, vector<vector<int>> &queenArrangements,vector<int> &possibleQueenArrangement){
        if(col==n){
           queenArrangements.push_back(possibleQueenArrangement);
            return;
        }
        
        
        for(int row = 0;row<n;row++){
            if(isSafe(row,possibleQueenArrangement)){
                possibleQueenArrangement.push_back(row);
                solve(col+1,n,queenArrangements,possibleQueenArrangement);
                possibleQueenArrangement.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> queenArrangements;
        vector<int> possibleQueenArrangement;
        vector<vector<string>> ans;
        solve(0,n,queenArrangements,possibleQueenArrangement);
        string s = "";
        for(int i=0;i<n;i++){
            s+='.';
        }
        for(auto it:queenArrangements){
            vector<string> v;
            string temp = s;
            for(auto it1:it){
                cout<<it1<<" ";
                temp[it1] = 'Q';
                v.push_back(temp);
                temp[it1] = '.';
            }
            ans.push_back(v);
            cout<<endl;
        }
        return ans;
        
    }
};
