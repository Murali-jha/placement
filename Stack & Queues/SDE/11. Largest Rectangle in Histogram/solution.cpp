class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        vector<int> left(n),right(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            
            int x = s.empty()?-1:s.top();
            left[i] = x;
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            
            int x = s.empty()?n:s.top();
            right[i] = x;
            s.push(i);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans, heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};
