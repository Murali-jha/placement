
void insert(stack<int> &s,int x){
    if(s.size()==0 || s.top()<=x){
        s.push(x);
        return;
    }
    else{
        int a = s.top();
        s.pop();
        insert(s,x);
        s.push(a);
    }
}

void sortStack(stack<int> &st)
{
	// Write your code here
    if(st.size()==1)
        return;
    int x = st.top();
    st.pop();
    sortStack(st);
    stack<int> temp;
    insert(st,x);
}
