void calculateSpan(int price[], int n, int S[])
{
    // Create a stack and push index of first
    // element to it
    stack<int> st;
 
    // Calculate span values for rest of the elements
    for (int i = 0; i < n; i++) {
        // Pop elements from stack while stack is not
        // empty and top of stack is smaller than
        // price[i]
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
}
