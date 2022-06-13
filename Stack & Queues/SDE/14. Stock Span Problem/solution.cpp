class StockSpanner {
public:
    vector<int> v;
    stack<int> s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        int ans;
        int i = v.size()-1;
        while(!s.empty() && v[s.top()]<=v[i]){
            s.pop();
        }
        ans = s.empty()?i+1:i - s.top();
        s.push(i);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
