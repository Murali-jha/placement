class Solution {
public:
    string reverseWords(string s) {
        int j = s.length()-1;
        string temp = "";
        string ans = "";
        while(j>=0){
            if(s[j]==' '){
                if(temp!=""){
                    reverse(temp.begin(),temp.end());
                    ans+=temp;
                    ans+=' ';
                    temp="";
                }
            }
            else{
                temp += s[j];
            }
            j--;
        }
        if(temp==""){
            ans.pop_back();
            return ans;
        }
        else{
            reverse(temp.begin(),temp.end());
            ans+=temp;
            return ans;
        }
    }
};
