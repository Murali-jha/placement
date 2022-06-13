#include<queue>

void sortStack(stack<int> &stack)
{
	// Write your code here
    priority_queue<int,vector<int>,greater<int>> pq;
    while(!stack.empty()){
        pq.push(stack.top());
        stack.pop();
    }
    while(!pq.empty()){
        stack.push(pq.top());
        pq.pop();
    }
}
