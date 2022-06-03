class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev(1,1);
        int k = 2;
        numRows--;
        ans.push_back(prev);
        while(numRows--){
            vector<int> temp(k,1);
            for(int i=1;i<k-1;i++){
                temp[i] = prev[i] + prev[i-1];
            }
            k++;
            prev = temp;
            ans.push_back(temp);
        }
        return ans;
    }
};
