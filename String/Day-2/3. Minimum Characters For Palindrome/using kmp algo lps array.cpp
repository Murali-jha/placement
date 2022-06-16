#include<bits/stdc++.h>

int minCharsforPalindrome(string str) {
	// Write your code here.
	string temp = str;
    reverse(temp.begin(),temp.end());
    str = str + '$' + temp;
    
    int i=0;
    int j=1;
 
    vector<int> lps(str.length(),0);
    while(j<str.length()){
        while(i>0 && str[i]!=str[j]){
            i = lps[i-1];
        }
        if(str[i]==str[j]){
            i++;
        }
        lps[j]=i;
        j++;
    }
    
    return temp.length() - lps[str.length()-1];
}
