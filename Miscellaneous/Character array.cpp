/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

//hellp wprld nrfr fkmrk 
// hello /0

char* rotatewords(char* input1){
    vector<string> v;
    int i=0;
    string temp = "";
    while(input1[i]!='\0'){
        if(input1[i]==' '){
            v.push_back(temp);
            temp="";
        }
        else{
            temp+=input1[i];
        }
        i++;
    }
    v.push_back(temp);
    
    string ans = "";
    for(auto it:v){
        string s = it;
        reverse(s.begin(),s.end());
        ans += s;
        ans+=' ';
    }
    ans.pop_back();
    char p[ans.length()];
    // cout<<"ans "<<ans<<endl;
    // cout<<"p "<<p<<endl;
    int k = 0;
    
    for(auto it:ans){
        p[k++] = it;
    }
    p[k] = '\0';
    char *x = p;
    return x;
}

int main()
{
    //cout<<"Hello World";
    string s = "Hello world";
    char* k = &s[0];
    cout<<"k check "<<k<<endl;
    char* ans = rotatewords(k);
    cout<<"ans "<<ans;
    return 0;
}
