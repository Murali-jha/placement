class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss(version1);
        vector<string> v1;
        while(ss.good()){
            string temp;
            getline(ss,temp,'.');
            v1.push_back(temp);
        }
        
        
        stringstream ss1(version2);
        vector<string> v2;
        while(ss1.good()){
            string temp;
            getline(ss1,temp,'.');
            v2.push_back(temp);
        }
        
        int m = v1.size()>v2.size()?v1.size():v2.size();
        
        for(int i=0;i<m;i++){
            int x = i<v1.size()?stoi(v1[i]):0;
            int y = i<v2.size()?stoi(v2[i]):0;
            if(x<y){
                return -1;
            }
            else if(x>y){
                return 1;
            }
        }
        return 0;
    }
};
