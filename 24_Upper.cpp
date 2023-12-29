#include<iostream>
#include<string.h>
using namespace std;

void st(string s,int n){
    if(n==s.size()){
        return;
    }
    
    if(s[n] == ' '){
        cout << " ";
    }
    else if(s[n] == '.'){
        cout << ".";
    }
    
    else{
        int b = char(s[n]);
        s[n] = char(b-32);
        cout << s[n];
    }
    st(s,n+1);
}

int main()
{
    string s = "today is tuesday.";
    st(s,0);
    return 0 ;
}