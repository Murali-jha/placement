class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        
        string num = "11";
        int k = n-2;
        while(k--){
            string temp = "";
            int count =1;
            int i;
            for(i=1;i<num.size();i++){
                if(num[i-1]==num[i]){
                    count++;
                }
                else{
                    temp += to_string(count);
                    temp += num[i-1];
                    count=1;
                }
            }
            temp += to_string(count);
            temp += num[i-1];
            num = temp;
        }
        return num;
    }
};
