class Solution {
public:
    bool isValid(string st) {
        char s1 = '(';
        char s2 = ')';
        char s3 = '[';
        char s4 = ']';
        char s5 = '{';
        char s6 = '}';
        
        stack<char> s;
        for(auto it:st){
            if(it==s1 || it==s3 || it==s5){
                s.push(it);
            }
            else{
                if(s.empty()){
                    return false;
                }
                else if(it==s2 && s.top()!=s1){
                    return false;
                }
                else if(it==s4 && s.top()!=s3){
                    return false;
                }
                else if(it==s6 && s.top()!=s5){
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
};
