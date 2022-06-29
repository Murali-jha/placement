void solve(string s,string temp,int ind,vector<string> &ans){
	        if(temp!=""){
	            ans.push_back(temp);
	        }
	        for(int i=ind;i<s.length();i++){
	           // if(ind!=i && s[i]==s[i-1]){
	           //     continue;
	           // }
	            temp.push_back(s[i]);
	            solve(s,temp,i+1,ans);
	            temp.pop_back();
	        }
	    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string temp="";
		    solve(s,temp,0,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
