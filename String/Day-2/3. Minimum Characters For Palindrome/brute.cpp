#include<bits/stdc++.h>

bool isPalindrome(string s){
    int i = 0;
    int j = s.length()-1;
    
    while(i<j){
        if(s[i++]!=s[j--])
            return false;
    }
    return true;
}
int minCharsforPalindrome(string s) {
	// Write your code here.
    int cnt = 0;
	while(s.length()>0){
        if(isPalindrome(s)){
            break;
        }
        
        cnt++;
        s.erase(s.begin()+s.length()-1);
    }
    return cnt;
}
