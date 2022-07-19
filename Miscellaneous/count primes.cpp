class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
            return 0;
        vector<bool> v(n,true);
        v[0] = false;
        v[1] = false;
        int count = 0;
        for(int i=2;i<=sqrt(n);i++){
            if(v[i]){
                for(int j=i*i;j<n;j = j+i){
                    v[j]=false;
                }
            }
        }
        for(auto it:v){
            if(it==true)
                count++;
        }
        return count;
    }
};
