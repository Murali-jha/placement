class Solution {
public:
    string getPermutation(int n, int k) {
        int x = n;
        string s = "";
        for(int i=1;i<=n;i++){
            s += to_string(i);
        }
        cout<<s<<endl;
        k--;
        while(k--){
            next_permutation(s.begin(),s.end());
        }
        return s;
    }
};
