#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> v(n);
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()>=arr[i])
            s.pop();
        
        int x = s.empty()?-1:s.top();
        v[i] = x;
        s.push(arr[i]);
    }
    
    return v;
}
