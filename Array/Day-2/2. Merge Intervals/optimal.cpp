class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0 || intervals.size()==1){
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end());
        int m = intervals.size();
        ans.push_back(intervals[0]);
        int j = 0;
        for(int i=1;i<m;i++){
            if(ans[j][1]<intervals[i][0]){
                ans.push_back(intervals[i]);
                j++;
            }
            else if(ans[j][1]<intervals[i][1]){
                ans[j][1] = intervals[i][1];
            }
        }
        return ans;
    }
};
