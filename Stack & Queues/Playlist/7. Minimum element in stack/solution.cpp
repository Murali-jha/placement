stack<int> ss;

void push(stack<int>& s, int a){
	// Your code goes here
	if(ss.size()==0 || ss.top()>=a){
	    ss.push(a);
	}
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size()==n){
	    return true;
	}
	return false;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.size()==0){
	    return true;
	}
	return false;
}

int pop(stack<int>& s){
	// Your code goes here
	if(s.empty()){
	    return -1;
	}
	if(s.top()==ss.top()){
	    ss.pop();
	}
	s.pop();
}

int getMin(stack<int>& s){
	// Your code goes here
	if(s.empty()){
	    return -1;
	}
	return ss.top();
}
