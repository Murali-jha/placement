vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    int sum = 0;
    vector<int> ans;
    int i=0;
    int j = 0;
    int patValue = 0;
    for(auto it:pat){
        patValue += (it-'A'+1);
    }
    while(j<str.length()){
        sum += (str[j] - 'A' + 1);
        if(j-i+1==pat.length()){
            if(sum==patValue){
                if(str.substr(i,pat.length())==pat){
                    ans.push_back(i);
                }
            }
            sum -= (str[i] - 'A' + 1);
            i++;
        }
        j++;
    }
    return ans;
}
