void sortStack(stack<int> &st)
{
	// Write your code here
    if(st.size()==1)
        return;
    int x = st.top();
    st.pop();
    sortStack(st);
    stack<int> temp;
    while(!st.empty() && st.top()>x){
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}
